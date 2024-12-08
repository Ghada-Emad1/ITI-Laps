const matchTime = /^(\d{2}):(\d{2}):(\d{2})$/;

class Clock {
    #intervalId;
    constructor(initialTime) {
        const matches = initialTime.match(matchTime);
        this.hours = parseInt(matches[1]);
        this.minutes = parseInt(matches[2]);
        this.seconds = parseInt(matches[3]);
    }
    static formatTime(clock) {
        return `${clock.hours}:${clock.minutes}:${clock.seconds}`;
    }
    #tick() {
        this.seconds += 1;
        if (this.seconds >= 60) {
            this.minutes += 1;
            this.seconds = 0;
        }
        if (this.minutes >= 60) {
            this.hours += 1;
            this.minutes = 0;
        }
        if (this.hours >= 24) {
            this.hours = 0;
        }
    }
    start() {
        this.#intervalId = setInterval(() => {
            this.#tick();
        }, 1000);
    }
    stop() {
        clearInterval(this.#intervalId);
    }
    get intervalId() {
        return this.#intervalId;
    }
    set intervalId(intervalId) {
        this.#intervalId = intervalId;
    }
    getTime() {
        return `${this.hours}:${this.minutes}:${this.seconds}`;
    }
}

class AlarmClock extends Clock {
    #alarmTime;
    constructor(initialTime, alarmTime) {
        super(initialTime);
        const matches = alarmTime.match(matchTime);
        this.#alarmTime = `${parseInt(matches[1])}:${parseInt(matches[2])}:${parseInt(matches[3])}`;
    }
    #checkAlarm() {
        if (this.getTime() === this.#alarmTime) {
            console.log("Wake UP Now!!");
            super.stop();
        }
    }
    start() {
        super.start();
        this.intervalId = setInterval(() => {
            this.#checkAlarm();
            console.log(this.getTime());
        }, 1000);
    }
    setAlarm(newAlarmTime) {
        const matches = newAlarmTime.match(matchTime);
        //console.log(matches)
        this.#alarmTime = `${parseInt(matches[1])}:${parseInt(matches[2])}:${parseInt(matches[3])}`;
    }
}

let alarm = new AlarmClock("14:59:55", "15:00:00");
alarm.start();
setTimeout(() => {
    alarm.setAlarm("15:01:00");
}, 10000);