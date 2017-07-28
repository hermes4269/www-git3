<?
$ARR_input_control_regexp[1] = "^.+@.+\..+$";//email
$ARR_input_control_regexp[2] = "^[a-zA-Z0-9]{6,20}$";//password		
$ARR_input_control_regexp[3] = "^[0-9/_\-\+\(\)]{8,30}$";//broj telefona
$ARR_input_control_regexp[4] = "^.{1,100}$";//ime						
$ARR_input_control_regexp[5] = "^[\s\S]{1,2000}$";//poruka				
$ARR_input_control_regexp[7] = "^\d+(\.\d{1,2})?$";//float sa dve decimale
//$ARR_input_control_regexp[5] = "^[\d\w\s]{1,2000}$";//poruka		
	
function mf_simetical_crypt_1($smer,$ulaz)
{
  switch($smer){
  case "en":
  				$izlaz=($ulaz )+579;
  				break;
  case "de":
  				$izlaz=$ulaz - 579;
  				break;  				
  }
  return $izlaz;
}

function mf_simetical_crypt_2($smer,$ulaz)
{
	//$key = 'password to (en/de)crypt';
	//$string = ' string to be encrypted '; // note the spaces
	$key = 'ljkhkhadhluzozztzgdzu8444y';
	//$string = 'goran andab'; // note the spaces
	$string=$ulaz;
  switch($smer){
  case "en":
  				$encrypted = base64_encode(mcrypt_encrypt(MCRYPT_RIJNDAEL_256, md5($key), $string, MCRYPT_MODE_CBC, md5(md5($key))));
  				$izlaz=$encrypted;
  				break;
  case "de":
  				$encrypted=$ulaz;
					$decrypted = rtrim(mcrypt_decrypt(MCRYPT_RIJNDAEL_256, md5($key), base64_decode($encrypted), MCRYPT_MODE_CBC, md5(md5($key))), "\0");
  				$izlaz=$decrypted;
  				break;  				
  }
  return $izlaz;
}



function mf_prikazi_gresku($poruka='ERROR 9.9')
{
  printf("<br/><br/><br/><BLOCKQUOTE><BLOCKQUOTE><BLOCKQUOTE><H3><FONT COLOR =\"#CC0000\">%s</FONT></H3></BLOCKQUOTE></BLOCKQUOTE></BLOCKQUOTE>\n",$poruka);
}

//-------------------------------------------------------

function mf_prikazi_poruku_glasanja($poruka)
{
  printf("<br/><br/><BLOCKQUOTE><BLOCKQUOTE><BLOCKQUOTE><H3><FONT COLOR =\"#CC0000\">%s</FONT></H3></BLOCKQUOTE></BLOCKQUOTE></BLOCKQUOTE>\n",$poruka);
}



//-------------------------------------------------------

/*
function mb_strtoupper($str)
{
//  return mb_strtoupper($str,"Windows-1251");

//  return mb_strtoupper($str,"utf-8");
 return mb_strtoupper($str);
}
*/

//-------------------------------------------------------
function mojdate($l,$formadatuma,$vremepounixu)
{
global $hc_ms_lang_date_format;
switch($hc_ms_lang_date_format[$l]){
case "1":
  
	switch($formadatuma){
	case "31.12.2008":
  		return date("d.m.Y.",$vremepounixu);
		break;
	case"31.12.2008. 23:45":
  		return date("d.m.Y. H:i",$vremepounixu);
		break;
	case"31122008":
  		return date("d.m.Y.",$vremepounixu);
		break;	  
	case"20081231234500":
  		return date("YmdHis",$vremepounixu);
		break;
	}	  
  	break;
case "2":
  
	switch($formadatuma){
	case "31.12.2008":
  		return date("j M Y",$vremepounixu);
		break;
	case"31.12.2008. 23:45":
  		return date("j M Y H:i",$vremepounixu);
		break;
	case"31122008":
  		return date("j M Y",$vremepounixu);
		break;
	case"20081231234500":
  		return date("YmdHis",$vremepounixu);
		break;

	}	  
  	break;
}
}

//-------------------------------------------------------

function mojmail($mm_adresa,$mm_subject,$mm_body,$mm_from)
{
global $hc_ms_mail_prikaz_na_ekranu, $hc_ms_mail_slanje;
		
		if($hc_ms_mail_prikaz_na_ekranu=="1"){

		  printf("<div style=\"position:fixed;\" ><hr/>add= %s<br/>sub= %s<br/>bod= %s<br/>fro= %s<br/></div>",$mm_adresa,$mm_subject,$mm_body,$mm_from);
		  
					   //$fl_mail_string=sprintf("add= %s sub= %s bod= %s fro= %s",$mm_adresa,$mm_subject,$mm_body,$mm_from);	  
		  /*js*/ //printf("	<script type=\"text/javascript\">						");
			/*js*/ //printf("    alert('%s')",$fl_mail_string);
			/*js*/ //printf(" </script>");
		  
		  
		}
		if($hc_ms_mail_slanje=="1"){
		  mb_send_mail($mm_adresa,$mm_subject,$mm_body,$mm_from);
		}


}

//-------------------------------------------------------
function mf_make_tail_crc()
{
 global $hc_cs_link_tail_hex_or_oct, $hc_cs_link_tail_separator_1, $hc_cs_link_tail_separator_2 ;
 
    $numargs = func_num_args();    
    $arg_list = func_get_args();
    $tail="";
    for ($i = 0; $i < $numargs; $i++) {
	switch($hc_cs_link_tail_hex_or_oct){
	case "1": 
        	  $tail.=$hc_cs_link_tail_separator_1.hexdec($arg_list[$i]);
        	break;
	case "2": 
        	$tail.=$hc_cs_link_tail_separator_1.$arg_list[$i];
        	break;
	}        
     }
    $tail = mb_substr($tail,1);
//  $tail_crc = $tail.",".dechex(crc32($tail));
//  uzimam samo deo
    $tail_crc = $tail.$hc_cs_link_tail_separator_1.substr(dechex(crc32($tail)),5);
    return($tail_crc);
}


//-------------------------------------------------------
function mf_make_link_crc()
{ 
global  $hc_cs_singlephppage_or_htmlredirection,$hc_ms_page_single_php_page_int,$hc_ms_path_internet_whole_code ; 
    switch($hc_cs_singlephppage_or_htmlredirection){
    case "1":
    		$link=$hc_ms_page_single_php_page_int."?x=".func_get_arg(0);
        	break;
    case "2":
    case "4":
    case "5":
    		$link=$hc_ms_path_internet_whole_code."/".func_get_arg(1)."-".func_get_arg(0).".htm";
        	break;
    case "3":
    		$link=$hc_ms_path_internet_whole_code."/".func_get_arg(1).".htm?x=".func_get_arg(0);
        	break;   
    }
    	
    return($link);
}



//------------------------------------------------------


function mf_make_link_crc_v2()
{ 
global  $hc_cs_singlephppage_or_htmlredirection,$hc_ms_page_single_php_page_int,$hc_ms_path_internet_whole_code ; 
 
    $fl_dir	=func_get_arg(5);
    if(func_get_arg(6)!="-"){
      $fl_file	=func_get_arg(6)."_".func_get_arg(2);
    }
    else{
       $fl_file	=func_get_arg(2);
    }    
    $fl_x	=func_get_arg(1);
    $fl_aclass	=func_get_arg(3);
    $fl_tekst	=func_get_arg(4);
    
    switch($hc_cs_singlephppage_or_htmlredirection){
    case "1":
    		$link =$hc_ms_page_single_php_page_int."?x=".$fl_x;
        	$ispis="<a href=\"".$hc_ms_page_single_php_page_int."?x=".$fl_x."\" class=\"".$fl_aclass. "\">".$fl_tekst."</a>";
        	break;
    case "2":
        	$link =$hc_ms_path_internet_whole_code."/".$fl_file."-".$fl_x.".htm";
        	//$ispis="<a href=\"".$hc_ms_path_internet_whole_code."/".$fl_file."-".$fl_x.".htm\" class=\"".$fl_aclass. "\">".$fl_tekst."</a>";
        	$ispis="<a href=\"".$hc_ms_path_internet_whole_code."/".$fl_dir."-".$fl_file."-".$fl_x.".htm\" class=\"".$fl_aclass. "\">".$fl_tekst."</a>";
        	
        	break;
   
    case "3":
        	$link =$hc_ms_path_internet_whole_code."/".$fl_file.".htm?x=".$fl_x;
        	//$ispis="<a href=\"".$hc_ms_path_internet_whole_code."/".$fl_file.".htm?x=".$fl_x."\" class=\"".$fl_aclass. "\">".$fl_tekst."</a>";
        	$ispis="<a href=\"".$hc_ms_path_internet_whole_code."/".$fl_dir."-".$fl_file.".htm?x=".$fl_x."\" class=\"".$fl_aclass. "\">".$fl_tekst."</a>";
        	break;
    case "4":
        	$link ="<a OnClick=\"prebacix('".$fl_x."','".$hc_ms_path_internet_whole_code."/".$fl_file."')\" class=\"".$fl_aclass. "\">".$fl_tekst."</a>";
        	$ispis="<a OnClick=\"prebacix('".$fl_x."','".$hc_ms_path_internet_whole_code."/".$fl_file."')\" class=\"".$fl_aclass. "\">".$fl_tekst."</a>";
        	break;
    case "5":
        	$link =$hc_ms_path_internet_whole_code."/".$fl_dir."/".$fl_x."/".$fl_file.".htm";
        	$ispis="<a href=\"".$hc_ms_path_internet_whole_code."/".$fl_dir."/".$fl_x."/".$fl_file.".htm\" class=\"".$fl_aclass. "\">".$fl_tekst."</a>";
        	break;  
    }
   $rezultat["ispis"]=$ispis;
   $rezultat["link"]=$link;
   return($rezultat);
}


//----------------------------------
function mf_make_enter_safe_for_input($lf_string_text,$lf_string_length){
		$fl_ulazni_string_za_search=$lf_string_text;
		$fl_ulazni_string_za_search=mb_substr($fl_ulazni_string_za_search, 0, $lf_string_length);
		//1	$fl_pripremljen_string_za_search=mysql_real_escape_string($fl_ulazni_string_za_search);			
   	$fl_pripremljen_string_za_search=$fl_ulazni_string_za_search;			
		$fl_pripremljen_string_za_search=html_entity_decode($fl_pripremljen_string_za_search);
   	$fl_pripremljen_string_za_search=strip_tags($fl_pripremljen_string_za_search);
		return($fl_pripremljen_string_za_search);
}

function mf_make_enter_safe($lf_string_text,$lf_string_length){
		$fl_ulazni_string_za_search=$lf_string_text;
		$fl_ulazni_string_za_search=mb_substr($fl_ulazni_string_za_search, 0, $lf_string_length);
		//printf("1-%s<br/>",$fl_ulazni_string_za_search);
//1		$fl_pripremljen_string_za_search=mysql_real_escape_string($fl_ulazni_string_za_search);			
	$fl_pripremljen_string_za_search=$fl_ulazni_string_za_search;			
		//printf("2-%s<br/>",$fl_pripremljen_string_za_search);		
		$fl_pripremljen_string_za_search=html_entity_decode($fl_pripremljen_string_za_search);
		//printf("3-%s<br/>",$fl_pripremljen_string_za_search);				
   	$fl_pripremljen_string_za_search=strip_tags($fl_pripremljen_string_za_search);
		//printf("4-%s<br/>",$fl_pripremljen_string_za_search);
// 		$fl_pripremljen_string_za_search= mb_ereg_replace('[^\d\w\s\*@]', ' ', $fl_pripremljen_string_za_search);
    //printf("6-%s<br/>",$fl_pripremljen_string_za_search);				
//  	$fl_pripremljen_string_za_search=" ".$fl_pripremljen_string_za_search;
//		$fl_pripremljen_string_za_search= preg_replace('/\s\s+/', ' ', $fl_pripremljen_string_za_search);		
		//printf("8-%s<br/>",$fl_pripremljen_string_za_search);		     		
		return($fl_pripremljen_string_za_search);
}

function mf_image_name_2_image_alt($lf_string_text){
	$lf_string_text=mb_ereg_replace(".jpg","",$lf_string_text);	
	$lf_string_text=mb_ereg_replace("-"," - ",$lf_string_text);
	$lf_string_text=mb_ereg_replace("_"," - ",$lf_string_text);
	$lf_string_text=mb_convert_case($lf_string_text, MB_CASE_TITLE);
	return($lf_string_text);
}

function mf_print_from_dek($fl_input_str,$fl_input_dek){
/*
$fl_input_str=$gr_val_1["jok_jok_type"];
$fl_input_dek=$MSG_dek_joke_heroes;
*/
if(($fl_input_str!='0') and ($fl_input_str!=',0,')){
	if(substr($fl_input_str, 0, 1)!=','){
		if (array_key_exists($fl_input_str, $fl_input_dek)) {			
		$fl_output_str=$fl_input_dek[$fl_input_str];
		}
		else{
			$fl_output_str='Nema u dek';
		}
	
	}
	else{
		$fl_output_str="";
		unset($fl_output_arr);
  	$fl_input_clean=substr($fl_input_str, 1);
  	$fl_input_clean=substr($fl_input_clean,0, -1);
  	$fl_output_arr=explode(",",$fl_input_clean);
  	while (list ($dkey, $dval) = each ($fl_output_arr)) { 
			if (array_key_exists($dval, $fl_input_dek)) {			
				$fl_output_str.=$fl_input_dek[$dval].", ";
			}
				else{
					$fl_output_str.='Nema u dek'.",";
			}
			//$fl_output_str.=$fl_input_dek[$dval].",";
		}
		$fl_output_str=substr($fl_output_str,0, -2);
	}
return $fl_output_str;
}//if(($fl_input_str!='0') and ($fl_input_str!=',0,')){
else{
return 'prazno';	
}
}








//----------------------------------
function mf_zamena8($lf_tip,$lf_ulazni_string){

$utf8_lat[1]=chr(hexdec("4C")).chr(hexdec("6A"));//Lj
$utf8_cir[1]=chr(hexdec("D0")).chr(hexdec("89"));

$utf8_lat[2]=chr(hexdec("4E")).chr(hexdec("6A"));//Nj
$utf8_cir[2]=chr(hexdec("D0")).chr(hexdec("8A")); 

$utf8_lat[3]=chr(hexdec("44")).chr(hexdec("C5")).chr(hexdec("BE"));//Dz
$utf8_cir[3]=chr(hexdec("D0")).chr(hexdec("8F")); 

$utf8_lat[4]=chr(hexdec("6C")).chr(hexdec("6A"));//lj
$utf8_cir[4]=chr(hexdec("D1")).chr(hexdec("99")); 

$utf8_lat[5]=chr(hexdec("6E")).chr(hexdec("6A"));//nj
$utf8_cir[5]=chr(hexdec("D1")).chr(hexdec("9A")); 

$utf8_lat[6]=chr(hexdec("64")).chr(hexdec("C5")).chr(hexdec("BE"));//dz
$utf8_cir[6]=chr(hexdec("D1")).chr(hexdec("9F"));

$utf8_lat[7]=chr(hexdec("4C")).chr(hexdec("4A"));//LJ
$utf8_cir[7]=chr(hexdec("D0")).chr(hexdec("89"));

$utf8_lat[8]=chr(hexdec("4E")).chr(hexdec("4A"));//NJ
$utf8_cir[8]=chr(hexdec("D0")).chr(hexdec("8A"));

$utf8_lat[9]=chr(hexdec("44")).chr(hexdec("C5")).chr(hexdec("BD"));//DZ
$utf8_cir[9]=chr(hexdec("D0")).chr(hexdec("8F"));

$utf8_lat[10]=chr(hexdec("C5")).chr(hexdec("A1"));//sh
$utf8_cir[10]=chr(hexdec("D1")).chr(hexdec("88"));

$utf8_lat[11]=chr(hexdec("C4")).chr(hexdec("8D"));//ch
$utf8_cir[11]=chr(hexdec("D1")).chr(hexdec("87"));

$utf8_lat[12]=chr(hexdec("C4")).chr(hexdec("91"));//dj
$utf8_cir[12]=chr(hexdec("D1")).chr(hexdec("92")); 

$utf8_lat[13]=chr(hexdec("C4")).chr(hexdec("87"));//cc
$utf8_cir[13]=chr(hexdec("D1")).chr(hexdec("9B")); 

$utf8_lat[14]=chr(hexdec("C5")).chr(hexdec("BE"));//zz
$utf8_cir[14]=chr(hexdec("D0")).chr(hexdec("B6")); 

$utf8_lat[15]=chr(hexdec("61"));//a
$utf8_cir[15]=chr(hexdec("61")); 

$utf8_lat[16]=chr(hexdec("62"));//b
$utf8_cir[16]=chr(hexdec("D0")).chr(hexdec("B1"));

$utf8_lat[17]=chr(hexdec("76"));//v
$utf8_cir[17]=chr(hexdec("D0")).chr(hexdec("B2"));

$utf8_lat[18]=chr(hexdec("67"));//g
$utf8_cir[18]=chr(hexdec("D0")).chr(hexdec("B3"));

$utf8_lat[19]=chr(hexdec("64"));//d
$utf8_cir[19]=chr(hexdec("D0")).chr(hexdec("B4"));

$utf8_lat[20]=chr(hexdec("65"));//e
$utf8_cir[20]=chr(hexdec("D0")).chr(hexdec("B5"));

$utf8_lat[21]=chr(hexdec("7A"));//z
$utf8_cir[21]=chr(hexdec("D0")).chr(hexdec("B7"));

$utf8_lat[22]=chr(hexdec("69"));//i
$utf8_cir[22]=chr(hexdec("D0")).chr(hexdec("B8"));

$utf8_lat[23]=chr(hexdec("6A"));//j
$utf8_cir[23]=chr(hexdec("D1")).chr(hexdec("98"));

$utf8_lat[24]=chr(hexdec("6B"));//k
$utf8_cir[24]=chr(hexdec("D0")).chr(hexdec("BA"));

$utf8_lat[25]=chr(hexdec("6C"));//l
$utf8_cir[25]=chr(hexdec("D0")).chr(hexdec("BB"));

$utf8_lat[26]=chr(hexdec("6D"));//m
$utf8_cir[26]=chr(hexdec("D0")).chr(hexdec("BC"));

$utf8_lat[27]=chr(hexdec("6E"));//n
$utf8_cir[27]=chr(hexdec("D0")).chr(hexdec("BD"));

$utf8_lat[28]=chr(hexdec("6F"));//o
$utf8_cir[28]=chr(hexdec("D0")).chr(hexdec("BE"));

$utf8_lat[29]=chr(hexdec("70"));//p
$utf8_cir[29]=chr(hexdec("D0")).chr(hexdec("BF"));

$utf8_lat[30]=chr(hexdec("72"));//r
$utf8_cir[30]=chr(hexdec("D1")).chr(hexdec("80"));

$utf8_lat[31]=chr(hexdec("73"));//s
$utf8_cir[31]=chr(hexdec("D1")).chr(hexdec("81"));

$utf8_lat[32]=chr(hexdec("74"));//t
$utf8_cir[32]=chr(hexdec("D1")).chr(hexdec("82"));

$utf8_lat[33]=chr(hexdec("75"));//u
$utf8_cir[33]=chr(hexdec("D1")).chr(hexdec("83"));

$utf8_lat[34]=chr(hexdec("66"));//f
$utf8_cir[34]=chr(hexdec("D1")).chr(hexdec("84"));

$utf8_lat[35]=chr(hexdec("68"));//h
$utf8_cir[35]=chr(hexdec("D1")).chr(hexdec("85"));

$utf8_lat[36]=chr(hexdec("63"));//c
$utf8_cir[36]=chr(hexdec("D1")).chr(hexdec("86"));

$utf8_lat[37]=chr(hexdec("C5")).chr(hexdec("A0")); //SH
$utf8_cir[37]=chr(hexdec("D0")).chr(hexdec("A8"));

$utf8_lat[38]=chr(hexdec("C4")).chr(hexdec("8C"));//CH
$utf8_cir[38]=chr(hexdec("D0")).chr(hexdec("A7"));

$utf8_lat[39]=chr(hexdec("C4")).chr(hexdec("90"));//DJ
$utf8_cir[39]=chr(hexdec("D0")).chr(hexdec("82"));

$utf8_lat[40]=chr(hexdec("C4")).chr(hexdec("86"));//CC
$utf8_cir[40]=chr(hexdec("D0")).chr(hexdec("8B"));

$utf8_lat[41]=chr(hexdec("C5")).chr(hexdec("BD"));//ZZ
$utf8_cir[41]=chr(hexdec("D0")).chr(hexdec("96"));

$utf8_lat[42]=chr(hexdec("41"));
$utf8_cir[42]=chr(hexdec("D0")).chr(hexdec("90"));//A

$utf8_lat[43]=chr(hexdec("42"));
$utf8_cir[43]=chr(hexdec("D0")).chr(hexdec("91"));//B

$utf8_lat[44]=chr(hexdec("56"));
$utf8_cir[44]=chr(hexdec("D0")).chr(hexdec("92"));//V

$utf8_lat[45]=chr(hexdec("47"));
$utf8_cir[45]=chr(hexdec("D0")).chr(hexdec("93"));//G

$utf8_lat[46]=chr(hexdec("44"));//D
$utf8_cir[46]=chr(hexdec("D0")).chr(hexdec("94"));

$utf8_lat[47]=chr(hexdec("45"));//E
$utf8_cir[47]=chr(hexdec("D0")).chr(hexdec("95"));

$utf8_lat[48]=chr(hexdec("5A"));//Z
$utf8_cir[48]=chr(hexdec("D0")).chr(hexdec("97"));

$utf8_lat[49]=chr(hexdec("49"));//I
$utf8_cir[49]=chr(hexdec("D0")).chr(hexdec("98"));

$utf8_lat[50]=chr(hexdec("4A"));//J
$utf8_cir[50]=chr(hexdec("D0")).chr(hexdec("88"));

$utf8_lat[51]=chr(hexdec("4B"));//K
$utf8_cir[51]=chr(hexdec("D0")).chr(hexdec("9A"));

$utf8_lat[52]=chr(hexdec("4C"));//L
$utf8_cir[52]=chr(hexdec("D0")).chr(hexdec("9B"));

$utf8_lat[53]=chr(hexdec("4D"));//M
$utf8_cir[53]=chr(hexdec("D0")).chr(hexdec("9C"));

$utf8_lat[54]=chr(hexdec("4E"));//N
$utf8_cir[54]=chr(hexdec("D0")).chr(hexdec("9D"));

$utf8_lat[55]=chr(hexdec("4F"));//O
$utf8_cir[55]=chr(hexdec("D0")).chr(hexdec("9E"));

$utf8_lat[56]=chr(hexdec("50"));//P
$utf8_cir[56]=chr(hexdec("D0")).chr(hexdec("9F"));

$utf8_lat[57]=chr(hexdec("52"));//R
$utf8_cir[57]=chr(hexdec("D0")).chr(hexdec("A0"));

$utf8_lat[58]=chr(hexdec("53"));//S
$utf8_cir[58]=chr(hexdec("D0")).chr(hexdec("A1"));

$utf8_lat[59]=chr(hexdec("54"));//T
$utf8_cir[59]=chr(hexdec("D0")).chr(hexdec("A2"));

$utf8_lat[60]=chr(hexdec("55"));//U
$utf8_cir[60]=chr(hexdec("D0")).chr(hexdec("A3"));

$utf8_lat[61]=chr(hexdec("46"));//F
$utf8_cir[61]=chr(hexdec("D0")).chr(hexdec("A4"));

$utf8_lat[62]=chr(hexdec("48"));//H
$utf8_cir[62]=chr(hexdec("D0")).chr(hexdec("A5"));

$utf8_lat[63]=chr(hexdec("43"));//C
$utf8_cir[63]=chr(hexdec("D0")).chr(hexdec("A6"));

//-------

$utf8_lat[64]="&".$utf8_cir[27].$utf8_cir[16].$utf8_cir[31].$utf8_cir[29].";";
$utf8_cir[64]="&nbsp;";

$utf8_lat[65]="&".$utf8_cir[15].$utf8_cir[26].$utf8_cir[29].";";
$utf8_cir[65]="&amp;";

$utf8_lat[66]="&".$utf8_cir[25].$utf8_cir[32].";";
$utf8_cir[66]="&lt;";

$utf8_lat[67]="&".$utf8_cir[18].$utf8_cir[32].";";
$utf8_cir[67]="&gt;";

/*
$utf8_lat[68]="&".$utf8_cir[27].$utf8_cir[16].$utf8_cir[31].$utf8_cir[29].";";
$utf8_cir[68]="&quot;";
*/

 $lf_val_cir_konacan=$lf_ulazni_string;
 for($ii=1;$ii<=67;$ii++){
  $lf_val_cir_konacan=mb_ereg_replace($utf8_lat[$ii],$utf8_cir[$ii],$lf_val_cir_konacan);
 } 
 return $lf_val_cir_konacan;
}
//*********************************
function mf_translate_filed($lf_field){
  $lf_izlazni_sting="";
  $lf_radni_sting=$lf_field;
  $lf_radni_sting=mb_ereg_replace("<","#==#<",$lf_radni_sting);
  $lf_radni_sting=mb_ereg_replace(">",">#==#",$lf_radni_sting);
  $lf_niz_stringova=explode("#==#",$lf_radni_sting);
  foreach($lf_niz_stringova as $val){
    if (mb_strpos($val,"<") === false) {
       $lf_izlazni_sting.=mf_zamena8(1,$val);
    }
    else{
       $lf_izlazni_sting.=$val;
   }
  }
  return $lf_izlazni_sting;
}
//********************************
function mf_zamena_skini_kukice($lf_lang,$lf_ulazni_string){

switch($lf_lang){
case "1":

$utf8_lat[1]=chr(hexdec("C5")).chr(hexdec("A1"));//sh
$utf8_bez_kukice[1]=chr(hexdec("73"));//s

$utf8_lat[2]=chr(hexdec("C4")).chr(hexdec("8D"));//ch
$utf8_bez_kukice[2]=chr(hexdec("63"));//c

$utf8_lat[3]=chr(hexdec("C4")).chr(hexdec("91"));//dj
$utf8_bez_kukice[3]=chr(hexdec("64")).chr(hexdec("6A")); 

$utf8_lat[4]=chr(hexdec("C4")).chr(hexdec("87"));//cc
$utf8_bez_kukice[4]=chr(hexdec("63"));//c 

$utf8_lat[5]=chr(hexdec("C5")).chr(hexdec("BE"));//zz
$utf8_bez_kukice[5]=chr(hexdec("7A"));//z 

$utf8_lat[6]=chr(hexdec("C5")).chr(hexdec("A0")); //SH
$utf8_bez_kukice[6]=chr(hexdec("53"));//S

$utf8_lat[7]=chr(hexdec("C4")).chr(hexdec("8C"));//CH
$utf8_bez_kukice[7]=chr(hexdec("43"));//C

$utf8_lat[8]=chr(hexdec("C4")).chr(hexdec("90"));//DJ
$utf8_bez_kukice[8]=chr(hexdec("44")).chr(hexdec("4A"));

$utf8_lat[9]=chr(hexdec("C4")).chr(hexdec("86"));//CC
$utf8_bez_kukice[9]=chr(hexdec("43"));//C

$utf8_lat[10]=chr(hexdec("C5")).chr(hexdec("BD"));//ZZ
$utf8_bez_kukice[10]=chr(hexdec("5A"));//Z


 $lf_val_bez_kukice_konacan=$lf_ulazni_string;
 for($ii=1;$ii<=10;$ii++){
  $lf_val_bez_kukice_konacan=mb_ereg_replace($utf8_lat[$ii],$utf8_bez_kukice[$ii],$lf_val_bez_kukice_konacan);
 } 
 return $lf_val_bez_kukice_konacan;
}
break;

}//switch($lf_lang){


function curPageURL() {
 $pageURL = 'http';
 if ((isset($_SERVER["HTTPS"])) and ($_SERVER["HTTPS"] == "on")) {$pageURL .= "s";}
 $pageURL .= "://";
 if ($_SERVER["SERVER_PORT"] != "80") {
  $pageURL .= $_SERVER["SERVER_NAME"].":".$_SERVER["SERVER_PORT"].$_SERVER["REQUEST_URI"];
 } else {
  $pageURL .= $_SERVER["SERVER_NAME"].$_SERVER["REQUEST_URI"];
 }
 return $pageURL;
}
function curPageName() {
 return substr($_SERVER["SCRIPT_NAME"],strrpos($_SERVER["SCRIPT_NAME"],"/")+1);
}

?>