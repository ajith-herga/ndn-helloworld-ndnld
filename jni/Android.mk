LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

PREBUILT_SHARED_LIBRARIES := -lcontroller
LOCAL_LDLIBS += -L./ -lcontroller

LOCAL_MODULE    := HelloWorld
LOCAL_SRC_FILES := helloworld.c Utility.c CcnClient.c SeqNum.c NdnlpPkt.c DataPkt.c AckPkt.c MsgSlicer.c PartialMsg.c SentPkt.c AckQueue.c Link.c NdnlpSvc.c ConnMgmt.c inet_adjust.c
LOCAL_CFLAGS := -g -Wall -Wpointer-arith -Wreturn-type -Wstrict-prototypes -D_BSD_SOURCE -std=gnu99 -I/usr/local/include/ -lccn -lcrypto -B/usr/local/lib/


include $(BUILD_SHARED_LIBRARY)

