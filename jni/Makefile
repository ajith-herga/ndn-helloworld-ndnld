CC = gcc 
CFLAGS = -g -Wall -shared -Wpointer-arith -Wreturn-type -Wstrict-prototypes -D_BSD_SOURCE -std=gnu99 -I/usr/local/include/  -I/usr/lib/jvm/java-6-openjdk-amd64/include/ 
LIBS = -lccn -lcrypto -lc -fPIC -B/usr/local/lib/
SRCS = Utility.c CcnClient.c SeqNum.c NdnlpPkt.c DataPkt.c AckPkt.c MsgSlicer.c PartialMsg.c SentPkt.c AckQueue.c Link.c NdnlpSvc.c ConnMgmt.c 

PROGRAMS = libctest.so

NDNLD_SRCS = $(SRCS) ctest.c
NDNLD_LIBS = $(LIBS)


ndnld: $(NDNLD_SRCS)
	$(CC) $(CFLAGS) -o libctest.so $(NDNLD_SRCS) $(NDNLD_LIBS)
