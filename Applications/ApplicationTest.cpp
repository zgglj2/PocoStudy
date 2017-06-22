#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/Task.h"
#include "Poco/TaskManager.h"
#include "Poco/DateTimeFormatter.h"
#include <Poco/Util/IntValidator.h>
#include <iostream>

using Poco::Util::Application;
using Poco::Util::ServerApplication;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::OptionCallback;
using Poco::Util::HelpFormatter;
using Poco::Util::IntValidator;
using Poco::Task;
using Poco::TaskManager;
using Poco::DateTimeFormatter;


class MyTask: public Task
{
public:
    MyTask(): Task("SampleTask")
    {
    }

    void runTask()
    {
        Application& app = Application::instance();
        while (!sleep(5000))
        {
            Application::instance().logger().information("busy doing nothing... " + DateTimeFormatter::format(app.uptime()));
        }
    }
};


class MyServerApp: public ServerApplication
{
public:
    MyServerApp(): _helpRequested(false)
    {
    }

    ~MyServerApp()
    {
    }

protected:
    void initialize(Application& self)
    {
        loadConfiguration(); // load default configuration files, if present
        ServerApplication::initialize(self);
//        logger().information("starting up");
    }

    void uninitialize()
    {
//        logger().information("shutting down");
        ServerApplication::uninitialize();
    }

    void defineOptions(OptionSet& options)
    {
        ServerApplication::defineOptions(options);

        options.addOption(
                Option("help", "h", "display help information on command line arguments")
                        .required(false)
                        .repeatable(false)
                        .callback(OptionCallback<MyServerApp>(this, &MyServerApp::handleHelp)));

        options.addOption(
                Option("define", "D", "define a configuration property")
                        .required(false)
                        .repeatable(true)
                        .argument("name=value")
                        .callback(OptionCallback<MyServerApp>(this, &MyServerApp::handleDefine)));

        options.addOption(
                Option("config-file", "f", "load configuration data from a file")
                        .required(false)
                        .repeatable(true)
                        .argument("file")
                        .callback(OptionCallback<MyServerApp>(this, &MyServerApp::handleConfig)));

        options.addOption(
                Option("bind", "b", "bind option value to test.property")
                        .required(false)
                        .repeatable(false)
                        .argument("value")
                        .validator(new IntValidator(0, 100))
                        .binding("test.properties"));
    }

    void handleHelp(const std::string& name, const std::string& value)
    {
        _helpRequested = true;
        displayHelp();
        stopOptionsProcessing();
    }

    void displayHelp()
    {
        HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("My server application that demonstrates some of the features of the Util::ServerApplication class.");
        helpFormatter.format(std::cout);
    }

    void defineProperty(const std::string &def) {
        std::string name;
        std::string value;
        std::string::size_type pos = def.find('=');
        if (pos != std::string::npos) {
            name.assign(def, 0, pos);
            value.assign(def, pos + 1, def.length() - pos);
        } else
            name = def;
        config().setString(name, value);
    }

    void handleDefine(const std::string &name, const std::string &value) {
        defineProperty(value);
    }

    void handleConfig(const std::string &name, const std::string &value) {
        loadConfiguration(value);
    }

    int main(const ArgVec& args)
    {
        if (!_helpRequested)
        {
            TaskManager tm;
            tm.start(new MyTask);
            waitForTerminationRequest();
            tm.cancelAll();
            tm.joinAll();
        }
        return Application::EXIT_OK;
    }

private:
    bool _helpRequested;
};


POCO_SERVER_MAIN(MyServerApp)
