<template>
  <div class="border">
    <div :id="middle ? 'middle' : ''" class="box">
      <span class="head">{{ name }}</span>
      <slot></slot>
    </div>
  </div>
</template>

<script setup>
const props = defineProps({
  name: {
    type: String,
    required: true,
    default: '标题'
  },
  middle: {
    type: Boolean,
    default: false
  }
})
</script>

<style scoped>
.head {
  font-weight: bold;
  margin: 10px;
}

.box {
  position: absolute;
  top: 50%;
  left: 5px;
  transform: translateY(-50%);
}

#middle {
  left: 50%;
  transform: translate(-50%, -50%);
}

.border {
  position: relative;
  height: 48px;
  padding: 10px;
  border: 1px solid RGB(171, 220, 255);
  border-radius: 5px;
  margin: 10px 0px;
  background-color: RGB(240, 250, 255);
}
</style>
