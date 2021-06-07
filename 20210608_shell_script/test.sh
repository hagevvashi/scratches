#!/usr/bin/env bash
set -euox pipefail

function test() {
  echo $TEST
}

test | grep foo
