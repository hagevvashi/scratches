#!/usr/bin/env bash

set -euo pipefail

GITHUB_REF=refs/heads/renovate/configure

HTTP_STATUS=$(curl \
  -X POST \
  -H "Content-Type: application/json" \
  -H "Circle-Token: $CIRCLECI_TOKEN" \
  -d "{\"branch\": \"${GITHUB_REF#refs/heads/}\", \"parameters\": { \"run-deploy\": true, \"deploy-destination\": \"staging\" } }" \
  https://circleci.com/api/v2/project/gh/****/***/pipeline \
  -o output \
  -w '%{http_code}\n' \
  -s)
if [ "$HTTP_STATUS" -lt 200 -o "$HTTP_STATUS" -ge 300 ]; then
  echo "API request for the CircleCI workflow fails with status code $HTTP_STATUS"
  echo 'the response body is'
  cat ./output
  exit 1
fi
