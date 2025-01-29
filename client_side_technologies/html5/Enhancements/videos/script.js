let myvideo=document.getElementById("myvideo");
let increaseSeekBar=document.querySelector("#autoIncrease");
function playPauseFun(e){
    if(myvideo.paused){
        myvideo.play();
        
        e.target.value="Pause";
    }else{
        myvideo.pause();
        e.target.value="Play";
        
    }
}

function changeMediaSize(e){
    switch (e.target.value){
        case "small":
            myvideo.width=myvideo.height=350;
            break;
        case "medium":
            myvideo.width=myvideo.height=450;
            break;
        case 'large':
            myvideo.width=myvideo.heig=550;
            break;
        case 'fullScreen':
            myvideo.requestFullscreen();
            break;
    }
}
function changeMediaVolume(e){
    myvideo.volume=e.target.value;
}
function changeSeekBar(e){
    myvideo.currentTime=e.target.value*myvideo.duration /100;
}

myvideo.addEventListener("timeupdate",()=>{
    const progress=(myvideo.currentTime/myvideo.duration)*100;
    increaseSeekBar.value=progress;
})

function muteFun(){
    myvideo.muted^=true;
}
function loopFun(){
    myvideo.loop^=true;

}
function forwardFun(){
    myvideo.playbackRate++;
}
function backwardFun(){
    myvideo.playbackRate--;
    if(myvideo.playbackRate<=0){
        myvideo.playbackRate=1;
    }
}

function changeSpeed(e){
    switch(e.target.value){
        case 'slowSpeed':
            myvideo.playbackRate=0.5;
            break;
        case 'normalSpeed':
            myvideo.playbackRate=1;
            break;
        case 'speedUp':
            myvideo.playbackRate=1.5;
            break;
        case 'speedtoTwo':
            myvideo.playbackRate=2;
            break;

    }
}



