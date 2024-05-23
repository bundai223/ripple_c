# src/ripple.cをビルドする
# 依存関係: src/ripple.c
# ターゲット: ripple
# ターゲットの依存関係: src/ripple.c

.PHONY: ripple_stackoverflow

ripple_stackoverflow: build build/ripple build/ripple_copilot

build:
	mkdir -p build

build/ripple: src/ripple.c
	clang -o $@ -lm $^

build/ripple_copilot: src/ripple_copilot.c
	clang -o $@ -lm $^


.PHONY: clean

clean:
	rm -f build/ripple build/ripple_copilot
