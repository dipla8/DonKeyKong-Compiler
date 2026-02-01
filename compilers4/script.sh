#!/usr/bin/env bash

OUT="out.asm"
IRIR="irir.asm"
TMP=$(mktemp)

awk '
############################
# PASS 1 — Read irir.asm   #
############################
FNR==NR {
    if ($1 == "start") {
        current = $2
        order[current] = 0
        next
    }
    if (current != "") {
        order[current]++
        blocks[current, order[current]] = $0
    }
    next
}

############################
# PASS 2 — Process out.asm #
############################
BEGIN {
    TAB = sprintf("%c", 9)   # actual tab character
}

/^[A-Za-z0-9_]+:/ {
    func = $0
    sub(/:$/, "", func)
    print
    next
}

/rest goes here/ {
    if (func in order) {
        for (i = 1; i <= order[func]; i++) {
            print TAB blocks[func, i]
        }
    } else {
        print TAB "; [no irir block found for " func "]"
    }
    next
}

{ print }
' "$IRIR" "$OUT" > "$TMP"

mv "$TMP" "$OUT"
echo "out.asm updated."

