echo \n
echo "\n"
echo \\
echo \\\
exit
echo \\\
echo \\\\
echo \
echo "\""
exit
sleep 100
exit
ls
exit
getconf ARG_MAX
exit
echo hoge hoge
echo aaaaaa               a
echo "aa" "aa"
echo "aaaa                     a"
echo aaaaaaa aaaaa
echo aa                                  a
ls
echo $SHELL
echo "hello $SHELL"
echo    aa     $SHELL
echo  \  aa     $SHELL
echo  \a  aa     $SHELL
echo \aa
echo \ab
ls
cat \env_test.c
ls
cat \ env_test.c
echo $
echo $$
echo $S
echo $a
echo $#
echo $aaa
echo $\
echo hello | cat <
echo hello | cat < 
echo hello | cat <   
echo hello | cat <   a
echo \n
echo "\n"
echo "\\n"
echo "\\\n"
echo "\\\n\"
"
echo $(SHELL)
echo $"SHELL"
echo $'SHELL'
echo $aaa
echo $ SHELL
echo $"
"
echo $""
echo $'SHELL'
echo 'SHELL'
echo \;
echo \; aa
echo \;     abc
echo \ 
echo \   a
echo "\a"
echo "\ "
echo "\ a"
echo "\$ a"
echo "\# a
"
echo "\# a"
echo "\; a"
echo "\> a"
echo "\( a"
echo "\$ a"
echo "\& a"
echo "\! a"
echo "\\ a"
echo \\ a
echo \ a

# \について
# echo \a
# など""で囲まれてなければ、aを出力する
# echo "\a"
# だと　\aと出力する
# ただし
# echo "\$a"
# $aと出力する
# ""内で、\の次に$, ", \のいずれかが来た時に特殊な対応をする
# また、シングルクォートを出力したいとき\'と入力することで引数として扱える
# ex) echo \'
# ex) echo \; \| \< \>


# $の特殊な挙動
# $以降の空白までの文字をすべて環境変数または特殊変数と解釈する
# ただし、一文字だけの場合は$を表示する
# echo $ --> $
# echo $a --> 定義されてなければ何も表示しない
# echo $'' ---> none
# ただし、
# echo $"SHELL"のようなとき
# SHELLと出力される
# $の次にクォートで始まる文字が来たら、なぜかクォートの中を展開する
# 変数展開もする

# echo "a""b" --> ab
# 連続したクォートは、空白がなければ一つの引数として解釈される

# ;について
# echo a;はＯＫだが、echo a ;   ;のように空白をはさんで;が2つ以上あると怒られる

# |について
# |の後コマンドがないと、複数行入力になってしまう
# bash: syntax error near unexpected token `|'
# として処理する。

# syntax error near unexpected tokenのnear unexpected tokenは実装が非常に難しい。
# これを公式bashと同様に再現するのはパターンが多すぎて調べきることは不可能。
# どんなエラーなのか、分類できるメッセージを書いてユーザーに渡す方がよさそう。

# ""や''の注意点
# echoではわかりづらいが、cat "" helloなどと入力すれば、
# catが第一引数に""をとっていることがわかる。""は空白と同じ解釈をするのではなく、
# {'\0'}と解釈するべき

# echo $envtestex ; echo below ; export envtestex=envtesthello ; echo $envtestex
# 上のコマンドを実行したとき、環境変数はプロセス実行時に決定するので、
# 結果

# below
# envtesthello
# になる。


# echo $foo; export foo=foo; echo $foo
# A; B ;C
# wait
# sleep 10 ; echo a ; cat foo
# echo aa | cat | wc