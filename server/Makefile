include ../common.inc

PROJECT_TARGET := stunserver
SHARED_OBJS :=  utils.o server.o stunconnection.o stunsocketthread.o tcpserver.o
PROJECT_OBJS := main.o $(SHARED_OBJS)

INCLUDES := $(BOOST_INCLUDE) $(OPENSSL_INCLUDE) -I../common -I../stuncore -I../networkutils -I../resources
LIB_PATH := -L../common -L../stuncore -L../networkutils
LIBS := -lnetworkutils -lstuncore -lcommon -pthread
SHARED_TARGET := lib$(PROJECT_TARGET).so
SHARED_FLAGS := -fPIC -shared
DEF := lib(PROJECT_TARGET).def

all: $(PROJECT_TARGET)

clean:
	rm -f $(PROJECT_OBJS) $(PROJECT_TARGET)

shared: $(PROJECT_OBJS)
	$(LINK.cpp) -o $(SHARED_TARGET) $(SHARED_FLAGS) $(SHARED_OBJS)

$(PROJECT_TARGET): $(PROJECT_OBJS)
	$(LINK.cpp) -o $@ $^ $(LIB_PATH) $(LIBS) $(SOCKET_LIBS) $(CRYPTO_LIBS) $(ASLR_FLAGS) $(PGO_LINK_FLAGS)


