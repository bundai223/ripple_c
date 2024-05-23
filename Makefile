# src/ripple.cをビルドする
# 依存関係: src/ripple.c
# ターゲット: ripple
# ターゲットの依存関係: src/ripple.c

.PHONY: ripple_stackoverflow

ripple_stackoverflow: ripple ripple_copilot

ripple: src/ripple.c
	clang -o $@ -lm $^

ripple_copilot: src/ripple_copilot.c
	clang -o $@ -lm $^


.PHONY: clean

clean:
	rm -f ripple ripple_copilot
