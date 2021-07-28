# redirect test

```shell
cat << EOS >! test.sh; chmod 755 ./test.sh; ./test.sh > /dev/null 2>&1
#!/usr/bin/env bash
set -euo pipefail

echo 'stdout'
echo 'stderr' 1>&2
EOS
```
