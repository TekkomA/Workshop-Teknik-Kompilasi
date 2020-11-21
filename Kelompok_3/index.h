const char MAIN_page[] PROGMEM = R"=====(
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, shrink-to-fit=no">
    <title>interface</title>
    <script src="https://kit.fontawesome.com/2e3ce63ccb.js" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css">
    <link rel="stylesheet" href="assets/css/styles.css">
</head>

<body>
    <div></div>
    <nav class="navbar navbar-light navbar-expand-md text-primary bg-light shadow" style="height: 37px;">
        <div class="container-fluid"><a class="navbar-brand text-primary" href="#" style="font-size: 15px;"><i class="fa fa-user-circle"></i>&nbsp; Kelompok 3</a><button class="navbar-toggler" data-toggle="collapse"><span class="sr-only">Toggle navigation</span><span class="navbar-toggler-icon"></span></button></div>
    </nav>
    <h1 class="text-center text-dark" style="font-size: 25px;margin: 14px;">Workshop Kompilasi</h1>
    <div>
        <div class="container">
            <div class="row">
                <div class="col-md-6">
                    <div class="card bg-light shadow-sm">
                        <div class="card-body">
                            <h4 class="text-center card-title">Control LED</h4>
                            <div></div>
                            <div class="text-center" style="height: 32px;"><a href="LEDON"><button class="btn btn-success btn-sm shadow-sm" type="button" style="font-size: 11px;width: 55px;">ON</button></a></div>
                            <div class="text-center" style="height: 32px;"><a href="LEDOFF"><button class="btn btn-danger btn-sm shadow-sm" type="button" style="font-size: 11px;width: 55px;">OFF</button></a></div>
                        </div>
                    </div>
                </div>
                <div class="col-md-6">
                    <div class="card bg-light shadow-sm" style="height: 146.8px;">
                        <div class="card-body">
                            <h4 class="text-center card-title">Potensiometer</h4>
                            <h4 class="text-center card-title">255</h4>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div></div>
    <div class="text-center" style="height: 32px;"></div>
    <script src="assets/js/jquery.min.js"></script>
    <script src="assets/bootstrap/js/bootstrap.min.js"></script>
</body>

</html>
)=====";
