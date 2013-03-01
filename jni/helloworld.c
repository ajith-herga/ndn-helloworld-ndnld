#include "com_testndk_HelloWorld.h"
/* helloworld.c  */

#include <jni.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "ndnld.h"
#include <android/log.h>

static void daemonize(void)
{
	if (getppid() == 1) return;
	pid_t pid = fork();
	if (pid < 0) exit(-1);
	if (pid > 0) exit(pid);
	umask(0);
	pid_t sid = setsid();
	if (sid < 0) exit(-2);
	if (chdir("/") < 0) exit(-3);
	freopen("/dev/null", "r", stdin);
	freopen("/dev/null", "w", stdout);
	freopen("/dev/null", "w", stderr);
}


JNIEXPORT jstring JNICALL Java_com_testndk_HelloWorld_CallNdnDaemon (JNIEnv * env, jobject jObj)
{

    __android_log_write(ANDROID_LOG_ERROR, "NDN", "Starting");
	CapsH_drop();
	PollMgr pm = PollMgr_ctor(50);
	CcnCC cc = CcnCC_ctor();
    if (!cc) {
        __android_log_write(ANDROID_LOG_ERROR, "NDN", "cc NULL");
        goto end;
    }
    if (!pm) {
        __android_log_write(ANDROID_LOG_ERROR, "NDN", "pm NULL");
        goto end;
    }
	CcnCC_pollAttach(cc, pm);
	ConnMgr cmgr = ConnMgr_ctor(pm, cc);

    if (!cmgr) {
        __android_log_write(ANDROID_LOG_ERROR, "NDN", "cmgr NULL");
        goto end;
    }

	while (true) {
		PollMgr_poll(pm);
		ConnMgr_run(cmgr);
	}

	ConnMgr_dtor(cmgr);
	CcnCC_pollDetach(cc, pm);
	CcnCC_dtor(cc);
	PollMgr_dtor(pm);
end:
	return (*env)->NewStringUTF(env, "OK");
}

JNIEXPORT jstring JNICALL Java_com_testndk_HelloWorld_messageFromNativeCode (JNIEnv * env, jobject jObj)
{

	return (*env)->NewStringUTF(env, "Hello World!. This is Sachin");
}
