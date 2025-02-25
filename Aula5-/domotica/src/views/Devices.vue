<script setup lang="ts">
// export default{
//     name: "Devices",
//     data() {
//         return {
//         contador: 0
//         }
//     },
//     methods:{
//         incrementar() {
//             this.contador ++;
//         },
//         decrementar() {
//             this.contador --;
//         },
//     } 
// }

import {ref} from 'vue';

const contador = ref(0);
const contar = ()=> {
    contador.value +=1;
    console.log(contador);
}
const descontar = ()=> {
    contador.value -=1;
    console.log(contador);
}
</script>

<template>
<h1>Hello Devices! Valor: {{ contador }}</h1>
<button @click="contar">incrementar</button>
<button @click="descontar">decrementar</button>
</template>

<style scoped lang="scss">

</style>