<template>
  <div>
    <NewButtonCG :companies="companies"></NewButtonCG>
  </div>
</template>

<script setup>
import NewButtonCG from '@/components/details/NewButtonCG.vue'

const companies = [
  { date: '2022-01-21', name: 'Company 1', address: 'Address 1' },
  { date: '2022-01-21', name: 'Company 2', address: 'Address 2' },
  { date: '2022-01-21', name: 'Company 3', address: 'Address 3' },
  { date: '2022-01-21', name: 'Company 4', address: 'Address 4' },
  { date: '2022-01-21', name: 'Company 5', address: 'Address 5' },
  { date: '2022-01-21', name: 'Company 6', address: 'Address 6' },
  { date: '2022-01-21', name: 'Company 7', address: 'Address 7' },
  { date: '2022-01-21', name: 'Company 8', address: 'Address 8' },
  { date: '2022-01-21', name: 'Company 9', address: 'Address 9' },
  { date: '2022-01-21', name: 'Company 10', address: 'Address 10' }
]
</script>

<style lang="scss" scoped></style>
