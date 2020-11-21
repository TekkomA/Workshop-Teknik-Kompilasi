<?php
$host="localhost:3306";
$user="kel_5";
$pass="aL351&kg";
$db="kompilasi";
$sambung=mysqli_connect($host, $user, $pass, $db);
if($sambung){
	$buka= mysqli_select_db($sambung, $db);
	if(!$buka){
		die("tidak konek");
	}
}
else{
	die("no konek");
}
?>