.PHONY: test test-types test-branches test-loops test-journal

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

test:
	bash scripts/test.sh all

test-types:
	bash scripts/test.sh types

test-branches:
	bash scripts/test.sh branches

test-loops:
	bash scripts/test.sh loops

test-journal:
	bash scripts/test.sh journal
