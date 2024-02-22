/* eslint-env node */
require('@rushstack/eslint-patch/modern-module-resolution')

module.exports = {
  root: true,
  extends: [
    'plugin:vue/vue3-essential',
    'plugin:vue/vue3-recommended',
    'eslint:recommended',
    '@vue/eslint-config-prettier'
  ],
  parserOptions: {
    ecmaVersion: 'latest'
  },
  rules: {
    "vue/no-multiple-template-root": "off",
    'space-before-function-paren': 0,
    'editor.detectIndentation': 0,
    'vue/multi-word-component-names': 0,
    'no-unused-vars': 0
  },
  env: {
    'vue/setup-compiler-macros': true,
    node: true
  }
}
