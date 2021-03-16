> _test.txt
echo $? >> _test.txt
echo "ciao" >> _test.txt
echo $? >> _test.txt
echo "ciao 123" >> _test.txt
echo $? >> _test.txt
echo "ciao\'\'\'" >> _test.txt
echo $? >> _test.txt
echo \'ciao\' >> _test.txt
echo $? >> _test.txt
echo $USER "pollo" >> _test.txt
echo $? >> _test.txt
echo 1234567890 +èùàò      123123 >> _test.txt
echo $? >> _test.txt
ls | grep mini >> _test.txt
echo $? >> _test.txt
ls | grep mini | grep x >> _test.txt
echo $? >> _test.txt
echo \"ciao\" >> _test.txt
echo $? >> _test.txt
ls | grep mini > ciao.txt; cat ciao.txt >> _test.txt
echo $? >> _test.txt
grep mi < ciao.txt >> ciao.txt >> _test.txt;
echo $? >> _test.txt
cat ciao.txt >> _test.txt; rm ciao.txt;
echo $? >> _test.txt
cd libft;
echo $PWD >> _test.txt;
cd ..;
echo $PWD >> _test.txt;
echo $? >> _test.txt
123
echo $? >> _test.txt
cd 123
echo $? >> _test.txt
ls 123
echo $? >> _test.txt
rm 123123123
echo $? >> _test.txt
'l''s' | "gre""p" 'm'ini >> _test.txt
echo $? >> _test.txt
echo m       a         q   w   e      42 > ciao.txt > miao.txt >> test.txt
echo $? >> _test.txt
cat ciao.txt >> _test.txt; cat miao.txt >> _test.txt;
echo $? >> _test.txt
ls | grep iao >> _test.txt
echo $? >> _test.txt
rm ciao.txt; rm miao.txt;
echo $? >> _test.txt
echo ';ls \;\;"' >> _test.txt
echo $? >> _test.txt
echo "FATTO"
