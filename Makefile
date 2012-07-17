CC = g++
LD = g++
CFLAGS = -c -Wall -O2
LDFLAGS = -s
RM = /bin/rm -f
OBJS = $(D_OBJ)main.o $(D_OBJ)helper.o
PLUGINS = $(D_PLUGINS)anitube.o \
	$(D_PLUGINS)avast.o \
	$(D_PLUGINS)avg.o \
	$(D_PLUGINS)blip.o \
	$(D_PLUGINS)blogspot.o \
	$(D_PLUGINS)fbcdn.o \
	$(D_PLUGINS)ggpht.o \
	$(D_PLUGINS)globo.o \
	$(D_PLUGINS)googlesyndication.o \
	$(D_PLUGINS)gstatic.o \
	$(D_PLUGINS)kaspersky.o \
	$(D_PLUGINS)metacafe.o \
	$(D_PLUGINS)modovideo.o \
	$(D_PLUGINS)msn.o \
	$(D_PLUGINS)netflix.o \
	$(D_PLUGINS)orkut.o \
	$(D_PLUGINS)phncdn.o \
	$(D_PLUGINS)photobucket.o \
	$(D_PLUGINS)pornhub.o \
	$(D_PLUGINS)porntube.o \
	$(D_PLUGINS)redtube.o \
	$(D_PLUGINS)sourceforge.o \
	$(D_PLUGINS)sun.o \
	$(D_PLUGINS)terratv.o \
	$(D_PLUGINS)tumblr.o \
	$(D_PLUGINS)tvuol.o \
	$(D_PLUGINS)videobb.o \
	$(D_PLUGINS)videologtv.o \
	$(D_PLUGINS)vimeo.o \
	$(D_PLUGINS)xvideos.o \
	$(D_PLUGINS)youtube.o \
	$(D_PLUGINS)ytimg.o 
D_PLUGINS = $(D_OBJ)plugins/
PROG = inComum
D_OBJ = obj/
SRC = src/
SRC_PLUGINS = $(SRC)plugins/

ifdef DEBUG
	CFLAGS += -Ddebug
	LDFLAGS += -Ddebug
endif
ifdef ENABLE_BOOST
	CFLAGS += -DENABLE_BOOST -lboost_regex
	LDFLAGS += -DENABLE_BOOST -lboost_regex
endif


all: $(PROG) 

# regra para linkar o programa
$(PROG): build_dirs $(OBJS) $(PLUGINS) 
	$(LD) $(LDFLAGS) $(OBJS) $(PLUGINS) -o $(PROG)

# classes principais
$(D_OBJ)%.o: $(SRC)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# plugins
$(D_PLUGINS)%.o: $(SRC_PLUGINS)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# regra para limpar arquivos que podem ser recompilados
clean:
	$(RM) $(PROG) $(OBJS) $(PLUGINS)

build_dirs: 
	@mkdir -p $(D_PLUGINS)
