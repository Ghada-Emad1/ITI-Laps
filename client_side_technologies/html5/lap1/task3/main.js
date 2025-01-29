const para=document.getElementsByTagName('p');
const maincheck=document.getElementById('main');
const localcheck=document.getElementById('local');

maincheck.addEventListener('change',function(){
    if(maincheck.checked){
        para[1].classList.add('checkedmain');
    }else{
        para[1].classList.remove('checkedmain');
    }
})

localcheck.addEventListener('change',function(){
    if(localcheck.checked){
        for(let i=2;i<9;i++){
            para[i].classList.add('checkedlocal');
        }
    }else{
        for(let i=2;i<9;i++){
            para[i].classList.remove('checkedlocal');
        }
    }
})