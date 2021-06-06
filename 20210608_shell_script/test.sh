#!/usr/bin/env bash
set -euo pipefail

function test() {
  echo $TEST
}

test | grep foo
