---
description: 比较两个文件是否相同
---

# 对拍脚本

{% code-tabs %}
{% code-tabs-item title="compare.sh" %}
```bash
#!/bin/bash

set -o nounset                              # Treat unset variables as an error

if [ $# != 2 ]
then
    echo "usage: $0 filename1 filename2"
    exit 1
fi

if [ ! -e $1 ]
then
    echo "$1 不存在"
    exit 2
fi

if [ ! -e $2 ]
then
    echo "$2 不存在"
    exit 3
fi

diff $1 $2 >/dev/null

if [ $? -eq 0 ]
then
    echo "两个文件相同"
else
    echo "两个文件不同"
fi
```
{% endcode-tabs-item %}
{% endcode-tabs %}



