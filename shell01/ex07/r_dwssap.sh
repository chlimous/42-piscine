cat /etc/passwd | cut -d ':' -f1,2,3,4,6,7 | awk "NR%2==0" | cut -d ':' -f1 | rev | sort -r | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | sed -z 's/\n/, /g' | rev | sed 's/ ,/./' | rev
