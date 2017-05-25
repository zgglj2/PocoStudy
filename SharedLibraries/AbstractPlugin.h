//
// Created by outer-glj on 2017/5/25.
//

#ifndef POCOSTUDY_ABSTRACTPLUGIN_H
#define POCOSTUDY_ABSTRACTPLUGIN_H

#include <string>

class AbstractPlugin {
public:
    AbstractPlugin();

    virtual ~AbstractPlugin();

    virtual std::string name() const = 0;
};


#endif //POCOSTUDY_ABSTRACTPLUGIN_H
