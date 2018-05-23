ifndef RMUTIL_LIBDIR
	RMUTIL_LIBDIR=../RedisModulesSDK/rmutil
endif

# find the OS
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

# Compile flags for linux / osx
ifeq ($(uname_S),Linux)
	SHOBJ_CFLAGS ?=  -fno-common -g -ggdb
	SHOBJ_LDFLAGS ?= -shared -Bsymbolic
else
	SHOBJ_CFLAGS ?= -dynamic -fno-common -g -ggdb
	SHOBJ_LDFLAGS ?= -bundle -undefined dynamic_lookup
endif
CFLAGS = -I../RedisModulesSDK/ -Wall -g -fPIC -lc -lm -std=gnu99  
CC=gcc

all: rmutil module.so

rmutil: FORCE
	$(MAKE) -C $(RMUTIL_LIBDIR)

module.so: module.o
	$(LD) -o $@ module.o $(SHOBJ_LDFLAGS) $(LIBS) -L$(RMUTIL_LIBDIR) -lrmutil -lc 

clean:
	rm -rf *.xo *.so *.o

FORCE:
