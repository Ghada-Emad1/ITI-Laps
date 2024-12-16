let basket = document.querySelector(".eggPacket");
let scoring = document.createElement("h1");
let cnt = 0;

class Basket {
    #leftValue;

    constructor(left, bottom) {
        this.left = left;
        this.bottom = bottom;
        basket.style.position = "absolute";
        basket.style.left = `${this.left}px`;
        basket.style.bottom = `${this.bottom}px`;
        this.#leftValue = this.left;
    }

    moveRight() {
        this.#leftValue += 10;
        if (this.#leftValue + basket.offsetWidth <= window.innerWidth) {
            basket.style.left = `${this.#leftValue}px`;
        }else{
            this.#leftValue-=10;
        }
    }

    moveLeft() {
        this.#leftValue -= 10;
        if (this.#leftValue >= 0) {
            basket.style.left = `${this.#leftValue}px`;
        }else{
            this.#leftValue+=10;
        }
    }
}

class Egg {
    #topValue;
    #fallEgg;
    #intervalId;

    constructor(left, top) {
        this.left = left;
        this.top = top;
        this.#fallEgg = document.createElement("img");
        this.#fallEgg.src = "../images/egg.webp";
        this.#fallEgg.width = 60;
        this.#fallEgg.height = 60;

        this.#fallEgg.style.position = "absolute";
        this.#fallEgg.style.left = Math.random() * (window.innerWidth-50) + "px";
        this.#fallEgg.style.top = `${this.top}px`;

        this.#topValue = this.top;
        document.body.appendChild(this.#fallEgg);
    }

    get Egg() {
        return this.#fallEgg;
    }

    falling() {
        this.#intervalId = setInterval(() => {
            this.#topValue += 10;

            if (this.#topValue + this.#fallEgg.offsetHeight <= window.innerHeight) {
                this.#fallEgg.style.top = `${this.#topValue}px`;
            } else {
                this.#fallEgg.src = "../images/broken_egg.jpeg";
                clearInterval(this.#intervalId);
                setTimeout(() => {
                    this.#fallEgg.remove();
                }, 500);
            }

            let basketRect = basket.getBoundingClientRect();
            let fallEggRect = this.#fallEgg.getBoundingClientRect();
            if (brokenEgg(basketRect, fallEggRect)) {
                scoring.innerText = `Scoring ${cnt}`;
                cnt++;
                document.body.appendChild(scoring);
                this.#fallEgg.style.display = "none";
                clearInterval(this.#intervalId);
            }
        }, 50);
    }

    stop() {
        clearInterval(this.#intervalId);
        this.#fallEgg.remove();
    }
}

function brokenEgg(fallEggRect, basketRect) {
    return (
        fallEggRect.bottom >= basketRect.top &&
        fallEggRect.top <= basketRect.bottom &&
        fallEggRect.left <= basketRect.right &&
        fallEggRect.right >= basketRect.left
    );
}

let activeEggs = [];

function FallingEgg() {
    const egg = new Egg(0, 0);
    egg.falling();
    activeEggs.push(egg);
}

function clearAllEggs() {
    activeEggs.forEach(egg => egg.stop());
    activeEggs = [];
}

function Timer() {
    let counting = 31;
    let timer = document.createElement("div");
    timer.style.color = "white";
    let start = document.createElement("button");

    start.innerText = `Start`;
    start.className = "startbtn";

    start.addEventListener("click", function () {
        let intervalId = setInterval(() => {
            FallingEgg();
            --counting;
            timer.innerHTML = `<p style="color:black;text-align:center;">You only have ${counting} seconds to finish</p>`;
            if (counting === 0) {
                timer.innerHTML = `<p style="color:red;text-align:center;">Your time is up!</p>`;
                clearInterval(intervalId);
                clearAllEggs();
                let result = document.createElement("div");
                result.style.textAlign = "center";
                result.style.fontSize = "24px";
                result.style.color = "black";
                result.innerText = cnt >= 10 ? `Your Score is ${cnt} You're a winner👏👏` : "You lose give it another";
                document.body.appendChild(result);
            }
        }, 1000);
    });

    document.body.appendChild(start);
    document.body.appendChild(timer);
}

let basketing = new Basket(100, 100);

Timer();

document.addEventListener("keydown", function (e) {
    if (e.key === "ArrowLeft") {
        basketing.moveLeft();
    }
    if (e.key === "ArrowRight") {
        basketing.moveRight();
    }
});

