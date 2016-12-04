#!/bin/bash

if [ $# -eq 0 ]; then
	list=$(ls *.h)
else
	list=$@
fi

mkdir cppDoc 2> /dev/null

function supprInutile()
{
	line0="$1"
	while :; do
		if [ "${line0:0:1}" = "	" ] || [ "${line0:0:1}" = "*" ]; then
			line0=${line0:1:${#line0}}
		else
			break
		fi
	done
}

echo "<html lang="fr">" > cppDoc/index.html
echo "	<head>" >> cppDoc/index.html
echo "		<meta charset="UTF-8">" >> cppDoc/index.html
echo "		<title>index</title>" >> cppDoc/index.html
echo "		<link rel="stylesheet" type="text/css"  href="style.css">" >> cppDoc/index.html
echo "		<script src="JavaScript.js"></script>" >> cppDoc/index.html
echo "	</head>" >> cppDoc/index.html
echo "	<body style=\"text-align:center; font-family: sans-serif\">" >> cppDoc/index.html
echo "		<table style=\"text-align: left; width: 50%; margin: auto; border-spacing:20px;\">" >> cppDoc/index.html

for file in $list; do

	name=$file"tml"

	echo "<tr><td style=\"background: #F0F0F0; padding:20px; border:solid black 3px;text-align:center;\"><a href=\"$name\" style=\"text-decoration:none; color:black\"><b>${name:0:$((${#name}-5))}</b></a></td></tr>" >> cppDoc/index.html
	
	echo "<html lang="fr">" > cppDoc/$name
	echo "	<head>" >> cppDoc/$name
	echo "		<meta charset="UTF-8">" >> cppDoc/$name
	echo "		<title>${name:0:$((${#name}-5))}</title>" >> cppDoc/$name
	echo "		<link rel="stylesheet" type="text/css"  href="style.css">" >> cppDoc/$name
	echo "		<script src="JavaScript.js"></script>" >> cppDoc/$name
	echo "	</head>" >> cppDoc/$name
	echo "	<body style=\"text-align:center; font-family: sans-serif\">" >> cppDoc/$name
	echo "	<a href="index.html" style=\"position:absolute;left:20px;text-decoration:none;color:black;border:solid black 2px;padding:5px;background:#F0F0F0;border-radius:10px;\">retour</a>" >> cppDoc/$name
	echo "		<h1>Classe ${file:0:$((${#file}-2))}</h1>" >> cppDoc/$name
	echo "		<table style=\"text-align: left; width: 50%; margin: auto; border-spacing:20px;\">" >> cppDoc/$name
	while read line; do
		if [ "${line:0:1}" = "*" ] || [ "${line:0:1}" = "/" ]; then
			if [ "${line:0:2}" = '/*' ]; then
				val="nomMethode"
			else if [ "$line" = '*/' ]; then
				val="fin"
			else
				if [ "${line:0:1}" = '*' ]; then
					supprInutile "$line"
					line=$line0
					if [ "$line" = "ARGS" ]; then
						val="args"
					else if [ "$line" = "RETURN VALUE" ]; then
						val="return"
					else if [ "$line" = "NOTE" ]; then
						val="note"
					else if [ "${line:0:1}" = '-' ]; then
						val="argument"
					else
						val="comun"
			fi fi fi fi fi fi fi
			if [ "$oldval" = "comun" ] && [ "$val" = "comun" ]; then
				oldline="$oldline $line"
				oldval="comun"
			else
				if [ "$oldval" = "comun" ]; then
					echo "<tr><td>$oldline</td></tr>" >> cppDoc/$name
				fi
				if [ "$val" = "args" ]; then
					echo "<tr><td><h3>arguments:</h3></td></tr>" >> cppDoc/$name
				fi 
				if [ "$val" = "return" ]; then
					echo "<tr><td><h3>valeur de retour:</h3></td></tr>" >> cppDoc/$name
				fi 
				if [ "$val" = "note" ]; then
					echo "<tr><td><h3>remarques:</h3></td></tr>" >> cppDoc/$name
				fi
				if [ "$val" = "nomMethode" ]; then
					echo "<tr><td style=\"background: #F0F0F0; padding:20px; border:solid black 3px;\"><table style=\"display: inline-block;\">" >> cppDoc/$name
					echo "<tr><td><h2>${line:2:${#line}}</h2></td></tr>" >> cppDoc/$name
				fi 
				if [ "$val" = "fin" ]; then
					echo "</table></td></tr>" >> cppDoc/$name
				fi 
				if [ "$val" = "argument" ]; then
					echo "<tr><td><b style=\"text-decoration:underline\">$line</b></td></tr><tr>" >> cppDoc/$name
				fi
				oldval=$val
				oldline=$line
			fi 
		fi
	done < $file
	echo "		</table>" >> cppDoc/$name
	echo "	</body>" >> cppDoc/$name
	echo "</html>" >> cppDoc/$name
done

echo "		</table>" >> cppDoc/index.html
echo "	</body>" >> cppDoc/index.html
echo "</html>" >> cppDoc/index.html
