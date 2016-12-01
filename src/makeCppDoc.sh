#!/bin/bash

if [ $# -eq 0 ]; then
	list=$(ls *.h)
else
	list=$@
fi

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

for file in $list; do

	name=$file"tml"
	
	echo "<html lang="fr">" > $name
	echo "	<head>" >> $name
	echo "		<meta charset="UTF-8">" >> $name
	echo "		<title>Sudoku</title>" >> $name
	echo "		<link rel="stylesheet" type="text/css"  href="style.css">" >> $name
	echo "		<script src="JavaScript.js"></script>" >> $name
	echo "	</head>" >> $name
	echo "	<body style=\"text-align:center; font-family: sans-serif\">" >> $name
	echo "		<h1>Classe ${file:0:$((${#file}-2))}</h1>" >> $name
	echo "		<table style=\"text-align: left; width: 50%; margin: auto; border-spacing:20px;\">" >> $name
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
					echo "<tr><td>$oldline</td></tr>" >> $name
				fi
				if [ "$val" = "args" ]; then
					echo "<tr><td><h3>arguments:</h3></td></tr>" >> $name
				fi 
				if [ "$val" = "return" ]; then
					echo "<tr><td><h3>valeur de retour:</h3></td></tr>" >> $name
				fi 
				if [ "$val" = "note" ]; then
					echo "<tr><td><h3>remarques:</h3></td></tr>" >> $name
				fi
				if [ "$val" = "nomMethode" ]; then
					echo "<tr><td style=\"background: #F0F0F0; padding:20px; border:solid black 3px;\"><table style=\"display: inline-block;\">" >> $name
					echo "<tr><td><h2>${line:2:${#line}}</h2></td></tr>" >> $name
				fi 
				if [ "$val" = "fin" ]; then
					echo "</table></td></tr>" >> $name
				fi 
				if [ "$val" = "argument" ]; then
					echo "<tr><td><b style=\"text-decoration:underline\">$line</b></td></tr><tr>" >> $name
				fi
				oldval=$val
				oldline=$line
			fi 
		fi
	done < $file
	echo "		</table>" >> $name
	echo "	</body>" >> $name
	echo "</html>" >> $name
done
