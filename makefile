OS = windows
ifeq ($(shell uname), Linux)
OS = linux
endif
ifeq ($(shell uname), Darwin)
OS = mac
endif

hpath = .\\h\\
cpppath = .\\cpp\\
opath = .\\o\\
remove = del
ifeq ($(OS), linux)
hpath = ./h/
cpppath = ./cpp/
opath = ./o/
remove = rm
endif
ifeq ($(OS), mac)
hpath = ./h/
cpppath = ./cpp/
opath = ./o/
remove = rm
endif

byyh = -02 -std=c++11 -w

#lSOURCES=$(wildcard $(cpppath)*.cxx)
sSOURCES=$(wildcard $(cpppath)*.cpp)
HEADERS=$(wildcard $(hpath)*.h)
#lOBJECTS=$(lSOURCES:%.cxx=%.o)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=main.exe
#LIB=main.a

#all: $(TARGET) $(LIB)
all: $(TARGET)
#$(TARGET): $(sOBJECTS) $(HEADERS) $(LIB)
$(TARGET): $(sOBJECTS) $(HEADERS)
	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) -o $(TARGET) 
#$(LIB): $(lOBJECTS) $(HEADERS)
#	@echo "Now Generating $(LIB) ..."
#	ar -rv $(LIB) $(lOBJECTS)
#	ranlib $(LIB)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@
#%.o: %.cxx $(HEADERS)
#	@echo "Now Compiling $< ..."
#	g++ -c $< -o $@
clean:
	$(remove) $(cpppath)*.o *.exe *.gch
explain:
#	@echo "Lib Sources: $(lSOURCES)"
	@echo "User Sources: $(sSOURCES)"
#	@echo "Lib Objects: $(lOBJECTS)"
	@echo "User Objects: $(sOBJECTS)"
#	@echo "Lib: $(LIB)"
	@echo "Target: $(TARGET)"
