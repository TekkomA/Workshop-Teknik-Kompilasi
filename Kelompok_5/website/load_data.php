<?php
	include("koneksi.php");

	//$sensor=rand()%100;
	$update_tanggal = mysqli_query($sambung, "UPDATE sensor SET tanggal=CURDATE()");
	$update_waktu = mysqli_query($sambung, "UPDATE sensor SET waktu=CURTIME()");
	//$update_sensor = mysqli_query($sambung, "UPDATE sensor SET data_sensor='$sensor'");

	$add_display = mysqli_query($sambung, "INSERT INTO display (id, tanggal, waktu, data_sensor,kondisi)
SELECT id, tanggal, waktu, data_sensor,kondisi FROM sensor");

  	$cek_display=mysqli_query($sambung, "SELECT * from display LIMIT 6 "); 
    if(mysqli_num_rows($cek_display)>5) 
    {
      	$delete_display = mysqli_query($sambung, "DELETE FROM display LIMIT 1 ");
    }
?>