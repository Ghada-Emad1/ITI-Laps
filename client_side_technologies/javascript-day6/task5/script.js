class Engine{
    static #count=0;
    constructor(source){
        if(this.constructor.name==="Engine"){
            throw new Error("Can't create object from this class")
        }
        Engine.#count++;
        this.source=source;
    }
    static get Count(){
        return Engine.#count;
    } 
}

// let eng1=new Engine();
// let eng2=new Engine();

// console.log(`Number of Engine : ${Engine.Count}`)

class Car extends Engine{
    #leftValue;
    constructor(top, left, source) {
        super(source);
        this.top = top;
        this.left = left;
        this.createImg = document.createElement("img");
        this.createImg.src = this.source;
        this.createImg.style.position = "absolute";
        this.createImg.style.top = this.top + "px";
        this.createImg.style.left = this.left + "px";
        document.body.appendChild(this.createImg);
        this.#leftValue = left;
    }

    set Top(value) {
        this.top = value;
        this.createImg.style.top = value + "px";
    }

    set Left(value) {
        this.left = value;
        this.createImg.style.left = value + "px";
    }

    moveRight() {
        let intervalId = setInterval(() => {
            this.#leftValue += 20;
            if (this.#leftValue + this.createImg.width+12< window.innerWidth) {
                this.createImg.style.left = this.#leftValue + "px";
                //console.log(this.createImg.style.left);
            } else {
                clearInterval(intervalId);
            }
        }, 500);
        const totalTime = ((window.innerWidth - this.#leftValue - this.createImg.width) / 20) * 500;
        return totalTime;
    }

    moveLeft() {
        let intervalId = setInterval(() => {
            this.#leftValue -= 20;
            if (this.#leftValue >= 0) {
                this.createImg.style.left = this.#leftValue + "px";
                //console.log(this.createImg.style.left);
            } else {
                clearInterval(intervalId);
            }
        }, 500);
    }
    changeStyle(styleObject){
       for(let styling in styleObject){
        this.createImg.style[styling]=styleObject[styling];
       }
    }
}

let car1 = new Car(100, 100, "../task1&2/images/bird.gif");
let car2=new Car(300,0,"../task1&2/images/8.jpg");
car1.Top = 20;
car1.Left = 20;

let rightTime=car1.moveRight();
let rightTime2=car2.moveRight();
//console.log(rightTime)
car1.changeStyle({
    border:"2px solid black",
    borderRadius:"10px",
})
car2.changeStyle({
    border:"2px solid black",
    borderRadius:"10px",
})
//console.log(car1);
setTimeout(() => {
    car1.moveLeft();
}, rightTime);
setTimeout(() => {
    car2.moveLeft();
}, rightTime2);
console.log("Number of Engine : ",Car.Count);