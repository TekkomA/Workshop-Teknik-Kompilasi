<?php
include 'koneksi.php';

if($_GET['req']=='update')
{
	$kondisi = $_GET['led_status'];
	$query = mysqli_query($sambung, "UPDATE sensor SET kondisi='$kondisi' WHERE id='1'");
}
?>
<!doctype html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7" lang=""> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8" lang=""> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9" lang=""> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang=""> <!--<![endif]-->
<head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>WORKSHOP KOMPILASI</title>
    <meta name="description" content="WORKSHOP KOMPILASI">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <link rel="apple-touch-icon" href="https://i.imgur.com/QRAUqs9.png">

    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/normalize.css@8.0.0/normalize.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.1.3/dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/font-awesome@4.7.0/css/font-awesome.min.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/lykmapipo/themify-icons@0.1.2/css/themify-icons.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/pixeden-stroke-7-icon@1.2.3/pe-icon-7-stroke/dist/pe-icon-7-stroke.min.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/flag-icon-css/3.2.0/css/flag-icon.min.css">
    <link rel="stylesheet" href="assets/css/cs-skin-elastic.css">
    <link rel="stylesheet" href="assets/css/stylee.css">
    <link rel="stylesheet" href="add.css">
    <!-- <script type="text/javascript" src="https://cdn.jsdelivr.net/html5shiv/3.7.3/html5shiv.min.js"></script> -->
    <link href="https://cdn.jsdelivr.net/npm/chartist@0.11.0/dist/chartist.min.css" rel="stylesheet">
    <link href="https://cdn.jsdelivr.net/npm/jqvmap@1.5.1/dist/jqvmap.min.css" rel="stylesheet">

    <link href="https://cdn.jsdelivr.net/npm/weathericons@2.1.0/css/weather-icons.css" rel="stylesheet" />
    <link href="https://cdn.jsdelivr.net/npm/fullcalendar@3.9.0/dist/fullcalendar.min.css" rel="stylesheet" />

    <script type="text/javascript" src="Chart.js"></script>

</head>

<body>
    <!-- Right Panel -->
        <!-- Header-->
        <header id="header" class="header">
            
        </header>
        <!-- /#header -->
        <!-- Content -->
        <div class="content">
            <!-- Animated -->
            <div class="animated fadeIn">
                <!--  Traffic  -->
                <div class="row">
                    <div class="col-lg-12">
                        
                        <div class="card">
                            <div class="card-body">
                                <h4 class="box-title"> Grafik Data Potensiometer </h4>
                            </div>
                            <div class="row">
                                <div class="card-body">
                                    <canvas id="myChart"></canvas>
                                <div id="cart"></div>
                                <div id="proc"></div>
                                </div>   
                            </div>
                        </div>
                    </div>
                </div>

                <div class="row">
                        <div class="col-lg-12">
                            <div class="card">
                                <div class="card-body">
                                    <h4 class="box-title">Data Potensiometer 10 Detik Terakhir</h4>

                                </div>
                                <div class="card-body">
                                    <div class="table-stats order-table ov-h">
                                        <table class="table ">
                                            <div id="data"></div>
                                        </table>
                                    </div> <!-- /.table-stats -->
                                </div>
                            </div> <!-- /.card -->
                        </div>
                </div> <!-- /.row -->
				<div class="row">
                        <div class="col-lg-12">
                            <div class="card">
                                <div class="card-body">
                                    <h4 class="box-title">Control LED</h4>
									<a href="index.php?req=update&led_status=1" class="btn" style="background:green;color:white">TURN ON LED</a>
									<a href="index.php?req=update&led_status=0" class="btn" style="background:red;color:white">TURN OFF LED</a>
                                </div>
                                <div class="card-body">
                                    
                                </div>
                            </div> <!-- /.card -->
                        </div>
                </div> <!-- /.row -->
            </div>    
        </div>
        <!-- /.content -->
        <div class="clearfix"></div>
        <!-- Footer -->
        <footer class="site-footer">
            <div class="footer-inner bg-white">
                <div class="row">
                    <div class="col-lg-6 text-center">
                        Copyright &copy; 2020 Kelompok 5 Workshop Teknik Kompilasi 
                    </div>
                    <div class="col-lg-12 text-right">
                        Designed by <a href="http://tekkom.pens.ac.id/">Kelompok 5 Workshop Teknik Kompilasi</a>
                    </div>
                </div>
            </div>
        </footer>
        <!-- /.site-footer -->
    
    <!-- /#right-panel -->

    <!-- Scripts -->
    <script src="jquery.js" type="text/javascript"></script>
    <script src="https://cdn.jsdelivr.net/npm/jquery@2.2.4/dist/jquery.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.14.4/dist/umd/popper.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.1.3/dist/js/bootstrap.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/jquery-match-height@0.7.2/dist/jquery.matchHeight.min.js"></script>
    <script src="assets/js/main.js"></script>

    <!--  Chart js -->
    <script src="https://cdn.jsdelivr.net/npm/chart.js@2.7.3/dist/Chart.bundle.min.js"></script>

    <!--Chartist Chart-->
    <script src="https://cdn.jsdelivr.net/npm/chartist@0.11.0/dist/chartist.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/chartist-plugin-legend@0.6.2/chartist-plugin-legend.min.js"></script>

    <script src="https://cdn.jsdelivr.net/npm/jquery.flot@0.8.3/jquery.flot.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/flot-pie@1.0.0/src/jquery.flot.pie.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/flot-spline@0.0.1/js/jquery.flot.spline.min.js"></script>

    <script src="https://cdn.jsdelivr.net/npm/simpleweather@3.1.0/jquery.simpleWeather.min.js"></script>
    <script src="assets/js/init/weather-init.js"></script>

    <script src="https://cdn.jsdelivr.net/npm/moment@2.22.2/moment.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/fullcalendar@3.9.0/dist/fullcalendar.min.js"></script>
    <script src="assets/js/init/fullcalendar-init.js"></script>

    <!--Local Stuff-->
</body>
<script type="text/javascript">
    var get_data = setInterval(function () {$('#cart').load('load_grafik.php').fadeIn("slow");}, 2000);
    var get_proc = setInterval(function () {$('#proc').load('load_data.php').fadeIn("slow");}, 2000);
    var get_tabel = setInterval(function () {$('#data').load('load_display.php').fadeIn("slow");}, 2000);
</script>

</html>
