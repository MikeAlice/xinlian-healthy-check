<template style="margin-bottom: 0px">
  <div class="main">
    <div class="top">
      <el-row justify="space-between">
        <el-col :style="{ display: code === undefined ? 'none' : 'flex' }" span="6">
          <div>
            <span class="text">{{ code }}</span>
          </div>
        </el-col>
        <el-col span="6">
          <div class="status">
            <span :class="report.style">{{ report.name }}</span>
          </div>
        </el-col>
        <el-col span="6">
          <div>
            <span class="text">{{ date }}</span>
          </div>
        </el-col>
        <el-col span="6">
          <div class="status">
            <span :class="sys.style">{{ sys.name }}</span>
          </div>
        </el-col>
      </el-row>
    </div>
    <div class="bottom">
      <el-row justify="space-between">
        <el-col span="12">
          <div>
            <span class="text">{{ company }}</span>
          </div>
        </el-col>
        <el-col span="12">
          <div class="status">
            <span :class="inspect.style">{{ inspect.name }}</span>
            <span :class="print.style">{{ print.name }}</span>
            <span :class="together.style">{{ together.name }}</span>
          </div>
        </el-col>
      </el-row>
    </div>
  </div>
</template>

<script setup>
const props = defineProps({
  // 编号
  code: String,
  // 日期
  date: String,
  // 单位
  company: String,
  // 使用图标：健 1、职 2 、从 3、放 4 等，默认不使用
  useSystem: {
    type: Number,
    default: 0
  },
  // 使用图标：未报(1)、已4报(2)，默认不使用
  useReport: {
    type: Number,
    default: 0
  },
  // 使用图标：审(1)、通(2)，默认不使用
  useInspect: {
    type: Number,
    default: 0
  },
  // 使用图标：未打(1)、已打(2)，默认不使用
  usePrint: {
    type: Number,
    default: 0
  },
  // 使用图标：个(1)、团(2)，默认不使用
  useTogether: {
    type: Number,
    default: 0
  }
})

// ['健', '职', '从', '放']
const sysIcon = [
  {
    name: '',
    style: ''
  },
  {
    name: '健',
    style: 'show healthy'
  },
  {
    name: '职',
    style: 'show job'
  },
  {
    name: '从',
    style: 'show follow'
  },
  {
    name: '放',
    style: 'show radiate'
  }
]
// ['未报', '已报']
const reportIcon = [
  {
    name: '',
    style: ''
  },
  {
    name: '未报',
    style: 'show no'
  },
  {
    name: '已报',
    style: 'show yes'
  }
]
// ['审','通']
const inspectIcon = [
  {
    name: '',
    style: ''
  },
  {
    name: '审',
    style: 'show no'
  },
  {
    name: '通',
    style: 'show yes'
  }
]
// ['未打', '已打']
const printIcon = [
  {
    name: '',
    style: ''
  },
  {
    name: '未打',
    style: 'show no'
  },
  {
    name: '已打',
    style: 'show yes'
  }
]
//['个', '团']
const togetherIcon = [
  {
    name: '',
    style: ''
  },
  {
    name: '个',
    style: 'show people'
  },
  {
    name: '团',
    style: 'show together'
  }
]

const sys = sysIcon[props.useSystem]
const report = reportIcon[props.useReport]
const inspect = inspectIcon[props.useInspect]
const print = printIcon[props.usePrint]
const together = togetherIcon[props.useTogether]
</script>

<style lang="scss" scoped>
// 设置边框
.main {
  color: black;
  // margin: 10px;
  width: 100%;

  .top {
    margin-bottom: 10px;
    width: 100%;
  }

  .bottom {
    // margin: 10px;
    width: 100%;
  }
}

// 显示文字的盒子
.text {
  margin: 2px;
}

// 图标盒子
.status {
  margin: 2px;
}

// 盒子默认隐藏
.status span {
  display: none;
  border: 1px solid;
  border-radius: 5px;
  padding: 4px;
  margin-right: 10px;
}

// 让盒子显示出来
.status .show {
  display: inline-block;
}

// sys的不同样式
.status {
  .healthy {
    color: green;
    border-color: green;
  }

  .job {
    color: orange;
    border-color: orange;
  }

  .follow {
    color: blue;
    border-color: blue;
  }

  .radiate {
    color: purple;
    border-color: purple;
  }
}

// report & inspect 的不同样式
.status {
  .no {
    color: orange;
    border-color: orange;
  }

  .yes {
    color: white;
    border-color: green;
    background-color: green;
  }
}

// together 的不同样式
.status {
  .people {
    color: green;
    border-color: green;
  }

  .together {
    color: red;
    border-color: red;
  }
}
</style>