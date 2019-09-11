#if __ANDROID__
#include<android/log.h>
#define LOG_TAG "samtools-native"
#endif

#ifdef __ANDROID__
#define PRINTTOSTREAM(file, arg, ...) fprintf(file, arg "\n",__VA_ARGS__)
#define STDOUT(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define STDERR(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define WARNING(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define ERROR(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define INFO(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define SUCCESS(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define DEBUG(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#else
#define PRINTTOSTREAM(file, arg, ...) fprintf(file, arg "\n", __VA_ARGS__)
#define STDOUT(arg, ...) fprintf(stdout, "[%s] " arg "\n", __func__,__VA_ARGS__)
#define STDERR(arg, ...) fprintf(stderr, "[%s] " arg "\n", __func__,__VA_ARGS__)
#define WARNING(arg, ...)   fprintf(stderr, "[%s::WARNING]\033[1;33m " arg "\033[0m\n", __func__,__VA_ARGS__)
#define ERROR(arg, ...) fprintf(stderr, "[%s::ERROR]\033[1;31m " arg "\033[0m\n", __func__,__VA_ARGS__)
#define INFO(arg, ...)  fprintf(stderr, "[%s::INFO]\033[1;34m " arg "\033[0m\n", __func__,__VA_ARGS__)
#define SUCCESS(arg, ...)   fprintf(stderr, "[%s::SUCCESS]\033[1;32m " arg "\033[0m\n", __func__,__VA_ARGS__)
#define DEBUG(arg, ...) fprintf(stderr,"[%s::DEBUG]\033[1;35m Error occured at %s:%d. " arg "\033[0m\n",__func__, __FILE__, __LINE__ - 2, __VA_ARGS__)
#endif