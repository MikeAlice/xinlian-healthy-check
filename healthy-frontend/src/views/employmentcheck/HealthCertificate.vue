<!-- 健康证管理 -->
<template>
  <div>健康证管理</div>
</template>

<script setup>
import {usehealthcertificatemanageStore} from '@/stores/healthcertificatemanage/index.js'
import {usePublicStore} from '@/stores/Public/index.js'

const healthcertificatemanageStore = usehealthcertificatemanageStore()

const PublicStore = usePublicStore()
</script>

<style lang="scss" scoped></style>
