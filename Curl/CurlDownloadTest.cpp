#include <iostream>
#include <stdio.h>
#include "curl/curl.h"

using namespace std;
static char errorBuffer[CURL_ERROR_SIZE];

static int writer(char *, size_t, size_t, string *);

static bool init(CURL *&, const char *, string *);

int main() {
    CURL *conn = NULL;
    CURLcode code;
    string buffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    std::string url = "http://tect.foryun.cn:8090/tect/cfg/tect.cfg";
    if (!init(conn, url.c_str(), &buffer)) {
        printf("Connection initializion failed\n");
        return -1;
    }
    code = curl_easy_perform(conn);

    if (code != CURLE_OK) {
        printf("Failed to get '%s' [%s]\n", url.c_str(), errorBuffer);
        return -1;
    }
    curl_easy_cleanup(conn);
    printf("%s\n", buffer.c_str());
    return 0;

}

static bool init(CURL *&conn, const char *url, string *p_buffer) {
    CURLcode code;
    conn = curl_easy_init();
    if (conn == NULL) {
        printf("Failed to create CURL connection\n");
        return false;
    }
    code = curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer);
    if (code != CURLE_OK) {
        printf("Failed to set error buffer [%d]\n", code);
        return false;
    }
    code = curl_easy_setopt(conn, CURLOPT_URL, url);
    if (code != CURLE_OK) {
        printf("Failed to set URL [%s]\n", errorBuffer);
        return false;
    }
    code = curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1);
    if (code != CURLE_OK) {
        printf("Failed to set redirect option [%s]\n", errorBuffer);
        return false;
    }
    code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
    if (code != CURLE_OK) {
        printf("Failed to set writer [%s]\n", errorBuffer);
        return false;
    }
    code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, p_buffer);
    if (code != CURLE_OK) {
        printf("Failed to set write data [%s]\n", errorBuffer);
        return false;
    }
    return true;
}

static int writer(char *data, size_t size, size_t nmemb, string *writerData) {
    unsigned long sizes = size * nmemb;
    if (writerData == NULL)
        return 0;
    writerData->append(data, sizes);
    return sizes;
}