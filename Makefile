include OptMake

.PHONY: src clean

DIRS=src unit_tests

all: $(DIRS)

src: 
	cd src/$(PL); $(MAKE) chief_justice

unit_tests: src
	cd unit_tests; $(MAKE) unit_tests

clean:
	cd libs; \
        rm -rf *; \
        cd $(SRC_DIR)/src/$(PL); \
        $(MAKE) clean; \
        cd $(SRC_DIR)/unit_tests; \
        $(MAKE) clean

