for i in `ls | grep -v "script1.sh\|script2.sh\|rec_s_2.sh\|script3.sh"` ;
 do 
 rm -rf $i;
  done
