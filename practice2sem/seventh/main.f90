program seventh

    real*8 k
    real*8 l

    print *, iau_S00B(2460133.02388D0, 2460129.02388D0)

    k = iau_S00B(2450123.7D0, 0D0)
    l = iau_S00B(2450123.5D0, 0.2D0)

    print *, k, l
    print *, l
    write (*, *) k, l

end program seventh
