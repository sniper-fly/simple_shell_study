PS1='$ '
echo "011_cd"
echo ""

echo "minishell\$ cd /"
cd /
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ ls"
ls
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ cd /bin"
cd /bin
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ ls"
ls
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ cd .."
cd ..
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ ls"
ls
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ cd ."
cd .
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ ls"
ls
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ cd bin"
cd bin
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ ls"
ls
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ cd ../"
cd ../
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ ls"
ls
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ cd /bin"
cd /bin
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ cd .././bin/.."
cd .././bin/..
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ ls"
ls
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ cd /zzz"
cd /zzz
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ cd"
cd
echo "minishell\$ "
echo "minishell\$ "

echo "minishell\$ mkdir tmp ; cd ./tmp ; echo $PWD ; echo $OLDPWD ; cd ../ ; rmdir tmp;"
mkdir tmp ; cd ./tmp ; echo $PWD ; echo $OLDPWD ; cd ../ ; rmdir tmp;
echo "minishell\$ "
echo "minishell\$ "
