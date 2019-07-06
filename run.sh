 #!/bin/bash

current_time=`date "+%Y-%m-%d_%H:%M"`

br_name=`git br | grep "*"`
br_name=${br_name/* /}
echo $br_name
gitlog=`git st | grep modified | awk '{print\$2}'`
addfile=`git st | grep new | awk '{print\$3}'`
gitlog=${gitlog}_${addfile}
file_name=""
echo $gitlog
echo "++++++++++++++++++++++++"
for lg in ${gitlog[@]}
do
echo '    '$lg
file_name=${file_name}__$lg
done
echo "++++++++++++++++++++++++"

#file_name=${gitlog/ /_/g}

msg=${current_time}_${br_name}_${file_name}

echo $msg

git pull
git commit -am $msg
git push


