<?php
	include("koneksi.php");

	$add = mysqli_query($sambung," UPDATE sensor SET data_sensor='".$_GET["temperature"]."' WHERE id='".$_GET["id"]."' ");
	$query =mysqli_query($sambung, "SELECT kondisi FROM sensor WHERE id='".$_GET["id"]."' ");
	
		while($row = mysqli_fetch_assoc($query)) 
		{
			echo "#";
			echo $row['kondisi'];
			echo "#@";
			// Echo data , equivalent with send data to esp
		}
?>