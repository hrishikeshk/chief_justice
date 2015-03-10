include OptMake

.PHONY: src clean

DIRS=src unit_tests

all: $(DIRS)

src: 
	cd src; $(MAKE) chief_justice

unit_tests: chief_justice
	cd unit_tests; $(MAKE) unit_tests

clean:
	cd libs; \
        rm -rf *.so; \
        cd $(SRC_DIR)/src; \
        $(MAKE) clean; \
        cd $(SRC_DIR)/unit_tests; \
        $(MAKE) clean
