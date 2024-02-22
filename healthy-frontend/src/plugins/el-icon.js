// 这里导入你要使用的图标
// 写成多行避免解决冲突麻烦
import { Menu } from '@element-plus/icons-vue'
import { Setting } from '@element-plus/icons-vue'
import { User } from '@element-plus/icons-vue'
import { Tickets } from '@element-plus/icons-vue'
import { UploadFilled } from '@element-plus/icons-vue'
import { Edit } from '@element-plus/icons-vue'
import { Delete } from '@element-plus/icons-vue'
import { View } from '@element-plus/icons-vue'
import { Refresh } from '@element-plus/icons-vue'
import { Bottom } from '@element-plus/icons-vue'
import { Fold } from '@element-plus/icons-vue'
import { ArrowLeftBold } from '@element-plus/icons-vue'
import { ArrowRightBold } from '@element-plus/icons-vue'
import { Plus } from '@element-plus/icons-vue'
import { Grid } from '@element-plus/icons-vue'
import { UserFilled } from '@element-plus/icons-vue'

export default (app) => {
  app.component('IconMenu', Menu)
  app.component('IconSetting', Setting)
  app.component('IconUser', User)
  app.component('IconTickets', Tickets)
  app.component('IconUpload', UploadFilled)
  app.component('IconEdit', Edit)
  app.component('IconDelete', Delete)
  app.component('IconView', View)
  app.component('IconRefresh', Refresh)
  app.component('IconBottom', Bottom)
  app.component('IconFold', Fold)
  app.component('IconArrowLeftBold', ArrowLeftBold)
  app.component('IconArrowRightBold', ArrowRightBold)
  app.component('IconArrowPlus', Plus)
  app.component('IconGrid', Grid)
  app.component('IconUserFilled', UserFilled)
}
