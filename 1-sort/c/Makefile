
objs := main.o
objs += 01-exchange.o 02-select.o 03-insert.o 04-merge.o 05-quick.o 06-bubble.c 07-heap.o 08-radix.o
objs += lib/utils.o

all: $(objs)
	gcc -o mysort ${objs}
	rm *.o

# % 是一個字串取代，代表dependence的檔名
# $< 是該rule dependence那串的第一個值
# $@ 是target的名稱
# $* 就是target，若有副檔名，就是拿掉副檔名後的那串
# $ ?表示dependence中，時間比target還新的部份
%.o: %.c
	gcc -c $< -o $@
