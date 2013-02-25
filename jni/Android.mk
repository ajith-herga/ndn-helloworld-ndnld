LOCAL_PATH := $(call my-dir)
ndk-build V=1

 include $(CLEAR_VARS)
 LOCAL_MODULE := foo-prebuilt
 LOCAL_SRC_FILES := ../libcontroller.so
 include $(PREBUILT_SHARED_LIBRARY)

  include $(CLEAR_VARS)


    LOCAL_MODULE    := HelloWorld
    LOCAL_SRC_FILES := helloworld.c Utility.c CcnClient.c SeqNum.c NdnlpPkt.c DataPkt.c AckPkt.c MsgSlicer.c PartialMsg.c SentPkt.c AckQueue.c Link.c NdnlpSvc.c ConnMgmt.c inet_adjust.c
    LOCAL_CFLAGS := -g -Wall -Wpointer-arith -Wreturn-type -Wstrict-prototypes -D_BSD_SOURCE -std=gnu99 -I/usr/local/include/ -lccn -lcrypto -B/usr/local/lib/

    LOCAL_SHARED_LIBRARIES := foo-prebuilt


  include $(BUILD_SHARED_LIBRARY)
