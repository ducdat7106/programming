function extra_zero_for_number_small(value) {
    return (value < 10) ? ('0' + value) : value;
}


function display_time_and_date() {
    var day_list = ["Sunday", "Monday", "Tuesday", "Wednesday ", "Thursday", "Friday", "Saturday"];

    var current_time_and_date = new Date();

    var second = current_time_and_date.getSeconds();
    var minute = current_time_and_date.getMinutes();
    var hours = current_time_and_date.getHours();

    var day = current_time_and_date.getDay(); // monday-->sunday

    var dates = current_time_and_date.getDate(); // 1-->31
    var month = current_time_and_date.getMonth() + 1;
    var year = current_time_and_date.getFullYear();

    minute = extra_zero_for_number_small(minute);
    hours = extra_zero_for_number_small(hours);
    second = extra_zero_for_number_small(second);
    month = extra_zero_for_number_small(month);
    dates = extra_zero_for_number_small(dates);

    var time = hours + ':' + minute + ':' + second;
    var date = day_list[day] + "\t" + dates + '/' + month + '/' + year;

    document.getElementById('time').innerHTML = time;
    document.getElementById('date').innerHTML = date;
}

setInterval(display_time_and_date, 500);