<?php
include "koneksi.php";

//DATA GRAFIK
$get_sensor_pompa= mysqli_query($sambung, "SELECT waktu, data_sensor FROM display ORDER BY waktu LIMIT 5");

while($show = mysqli_fetch_array($get_sensor_pompa)){
  $data_waktu[] = $show['waktu'];
  $data_sensor[] = $show['data_sensor'];
}

?>

<!DOCTYPE html>
<html>
<head>
  <script type="text/javascript" src="Chart.js"></script>
</head>
<body>
        
  <div style=" position: relative;  margin-top: 5px; width: 80px;height: 40px"></div>
  <script>
    var ctx = document.getElementById("myChart").getContext('2d');
    var myChart = new Chart(ctx, {
      type: 'line',
      data: {
        labels: <?php echo json_encode($data_waktu); ?>,
        datasets: [{
          label: "",
          data: <?php echo json_encode($data_sensor); ?>,
          backgroundColor: 'rgba(3, 169, 243, 0.2)',
          borderColor: 'rgba(3, 169, 243, 0.6)',
          borderWidth: 5
        }]
      },
      options: {
        scales: {
          yAxes: [{
            ticks: {
              beginAtZero:true
            }
          }]
        }
      }
    });
  </script>
</body>
</html>