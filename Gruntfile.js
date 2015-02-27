module.exports = function(grunt) {

  grunt.initConfig({

    sass: {
      dist: {
        files: {
          'css/main.css': 'css/main.sass'
        }
      }
    },

    watch: {
      sass: {
        files: 'css/main.sass',
        tasks: ['sass']
      }
    }


  });

  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-contrib-watch');

  grunt.registerTask('build', ['sass']);

  grunt.registerTask('default', ['sass', 'watch']);

};
