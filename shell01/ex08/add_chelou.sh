nb1=$(echo $FT_NBR1 | tr "\'\\\\\"\?\!" "01234")
nb2=$(echo $FT_NBR2 | tr "mrdoc" "01234")
res=$(echo "obase=13; ibase=5; $nb1+$nb2" | bc)
echo $res | tr "0123456789ABC" "gtaio luSnemf"
