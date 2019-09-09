# Find all the files which need to be compiled
include_directories(${PROJECT_SOURCE_DIR}/3rdparty/include)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/lz4)

set (bam bam.c config.h bam.h)
set (bam2bcf bam2bcf.c config.h bam2bcf.h)
set (bam2bcf_indel bam2bcf_indel.c config.h bam2bcf.h)
set (bam2depth bam2depth.c config.h samtools.h sam_opts.h)
set (coverage coverage.c config.h samtools.h sam_opts.h)
set (bam_addrprg bam_addrprg.c config.h samtools.h sam_opts.h)
set (bam_aux bam_aux.c config.h bam.h)
set (bam_cat bam_cat.c config.h samtools.h sam_opts.h)
set (bam_color bam_color.c config.h bam.h)
set (bam_fastq bam_fastq.c config.h samtools.h sam_opts.h)
set (bam_index bam_index.c config.h samtools.h sam_opts.h)
set (bam_lpileup bam_lpileup.c config.h bam_plbuf.h bam_lpileup.h)
set (bam_mate bam_mate.c config.h sam_opts.h samtools.h)
set (bam_md bam_md.c config.h sam_opts.h samtools.h)
set (bam_plbuf bam_plbuf.c config.h bam_plbuf.h)
set (bam_plcmd bam_plcmd.c config.h samtools.h sam_opts.h bam2bcf.h sample.h)
set (bam_quickcheck bam_quickcheck.c config.h)
set (bam_reheader bam_reheader.c config.h samtools.h)
set (bam_rmdup bam_rmdup.c config.h  sam_opts.h samtools.h bam.h)
set (bam_rmdupse bam_rmdupse.c config.h bam.h samtools.h)
set (bam_sort bam_sort.c config.h sam_opts.h samtools.h)
set (bam_split bam_split.c config.h sam_opts.h samtools.h)
set (bam_stat bam_stat.c config.h samtools.h sam_opts.h)
set (bam_tview bam_tview.c config.h bam_tview.h bam_lpileup.h samtools.h sam_opts.h)
set (bam_tview_curses bam_tview_curses.c config.h bam_tview.h bam_lpileup.h)
set (bam_tview_html bam_tview_html.c config.h bam_tview.h bam_lpileup.h)
set (bam_flags bam_flags.c config.h)
set (bamshuf bamshuf.c config.h samtools.h sam_opts.h)
set (bamtk bamtk.c config.h samtools.h version.h)
set (bedcov bedcov.c config.h samtools.h sam_opts.h)
set (bedidx bedidx.c config.h bedidx.h)   
set (cut_target cut_target.c config.h samtools.h sam_opts.h)
set (dict dict.c config.h)
set (faidx faidx.c config.h samtools.h)
set (padding padding.c config.h sam_opts.h samtools.h)
set (phase phase.c config.h sam_opts.h samtools.h)
set (sam sam.c config.h sam.h bam.h)
set (sam_opts sam_opts.c config.h sam_opts.h)
set (sam_utils sam_utils.c config.h samtools.h)
set (sam_view sam_view.c config.h samtools.h sam_opts.h bedidx.h)
set (sample sample.c config.h sample.h) 
set (stats_isize stats_isize.c config.h stats_isize.h) 
set (stats stats.c config.h samtools.h stats_isize.h sam_opts.h bedidx.h)
set (bam_markdup bam_markdup.c config.h sam_opts.h samtools.h tmp_file.h)
set (tmp_file tmp_file.c config.h tmp_file.h)  # ../lz4/lz4.h
set (LZ4 ../lz4/lz4.c ../lz4/lz4.h)

# Build a shared lib
add_library(samtoolshared SHARED ${bam} ${bam2bcf} ${bam2bcf_indel} ${bam2depth} ${coverage} ${bam_addrprg} ${bam_aux} ${bam_cat} ${bam_color} ${bam_fastq} ${bam_index} ${bam_lpileup}
		${bam_mate} ${bam_md} ${bam_plbuf} ${bam_plcmd} ${bam_quickcheck} ${bam_reheader} ${bam_rmdup} ${bam_rmdupse} ${bam_sort} ${bam_split} ${bam_stat} ${bam_tview}
		${bam_tview_curses} ${bam_tview_html} ${bam_flags} ${bamshuf} ${bamtk} ${bedcov} ${bedidx} ${cut_target} ${dict} ${faidx} ${padding} ${phase}
		${sam} ${sam_opts} ${sam_utils} ${sam_view} ${sample} ${stats_isize} ${stats} ${bam_markdup} ${tmp_file} ${LZ4})

# htslib dependency
set (htslib_static "${PROJECT_SOURCE_DIR}/3rdparty/${DEPLOY_PLATFORM}/libhts.a")

# link with dependencies
IF (${DEPLOY_PLATFORM} STREQUAL "x86")
	target_link_libraries(samtoolshared ${htslib_static} -lz -lpthread -ldl -lm)
ELSE()
	find_library(ANDROID_LOG_LIB log)
	target_link_libraries(samtoolshared ${htslib_static} ${ANDROID_LOG_LIB} -lz -ldl -lm)

ENDIF()