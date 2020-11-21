<?php
	include("koneksi.php");
	
	$hasil_sampling = mysqli_query($sambung, "SELECT tanggal, waktu, data_sensor,kondisi 
    FROM display ORDER BY waktu DESC LIMIT 5 ");
	
?>

<!DOCTYPE html>
<html>
<head>
	<title></title>
	<style>
	.btn_style1{
		border: 1px solid #cecece;
		padding: 3px 10px;
		box-shadow: 2px 2px 6px rgba(0, 0, 0, 0.4);
		color: white;
	}
	.btn_style1:hover{
		border: 1px solid #b1b1b1;
		box-shadow: 2px 2px 8px rgba(0, 0, 0, 0.5);
	}
	</style>
</head>
<body>
<table>
	<tr>
        <th>Tanggal</th>
        <th>Waktu</th>
        <th>Data Potensio</th>
        <th>Status LED</th>
	</tr>
	<?php
	while($show_sampling = mysqli_fetch_array($hasil_sampling)){
	?>
		<tr>
        <td width="250"><?php echo $show_sampling['tanggal'];?></td>
            <td width="250"><?php echo $show_sampling['waktu'];?></td>
            <td width="250"><?php echo $show_sampling['data_sensor'];?></td>
            <td width="250">
                <?php
                if ($show_sampling['kondisi'] == '1') {
                    echo "<button class=btn_style1 style=background:green>"."NYALA"."</button>";}
                
                else {
                    echo "<button class=btn_style1 style=background:red>"."MATI"."</button>";
                }
                ?>
            </td>
        </tr>
		<?php } ?>
</table>
</body>
</html>